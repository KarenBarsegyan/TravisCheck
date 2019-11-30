#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/Point.h"
#include "tf2_ros/transform_listener.h"
#include "tf/transform_listener.h"
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include "geometry_msgs/PolygonStamped.h"
#include "geometry_msgs/Twist.h"

void pixelTo3DPoint(const sensor_msgs::PointCloud2 &pCloud, const int u, const int v,
                    geometry_msgs::Point *p) {
    //  Convert from u (column / width), v (row/height) to position in array
    //  where X,Y,Z data starts
    int arrayPosition = v*pCloud.row_step + u*pCloud.point_step;

    //  compute position in array where x,y,z data start
    int arrayPosX = arrayPosition + pCloud.fields[0].offset;  // X has an offset of 0
    int arrayPosY = arrayPosition + pCloud.fields[1].offset;  // Y has an offset of 4
    int arrayPosZ = arrayPosition + pCloud.fields[2].offset;  // Z has an offset of 8

    float X = 0.0;
    float Y = 0.0;
    float Z = 0.0;

    memcpy(&X, &pCloud.data[arrayPosX], sizeof(float));
    memcpy(&Y, &pCloud.data[arrayPosY], sizeof(float));
    memcpy(&Z, &pCloud.data[arrayPosZ], sizeof(float));

    ROS_INFO("%f - %f", X, pCloud.data[arrayPosX]);

    //  put data into the point p
    p->x = X;
    p->y = Y;
    p->z = Z;
}

void Marker(visualization_msgs::Marker *marker, float x, float y, int i, int j) {
    marker->header.frame_id = "gotthard/base_link";
    marker->header.stamp = ros::Time(0);
    marker->ns = "lidar_namespace";
    marker->id = i;
    marker->type = visualization_msgs::Marker::CYLINDER;
    marker->action = visualization_msgs::Marker::ADD;
    marker->pose.position.x = x;
    marker->pose.position.y = y;
    marker->pose.position.z = 1;
    marker->pose.orientation.x = 0.0;
    marker->pose.orientation.y = 0.0;
    marker->pose.orientation.z = 0.0;
    marker->pose.orientation.w = 1.0;
    marker->scale.x = 0.2;
    marker->scale.y = 0.2;
    marker->scale.z = 2.0;
    marker->color.a = 1.0;  //  Don't forget to set the alpha!
    marker->color.r = 0.0;
    marker->color.g = 1.0;
    marker->color.b = 0.0;

    if (j == -1) {
        marker->color.a = 0.0;
    }
}

float x[100];
float y[100];
int amount = 0;

void scanCallBack(const sensor_msgs::PointCloud2 msg) {
    geometry_msgs::Point p;

    amount = msg.width;

    for (int i = 0; i < amount; i++) {
        pixelTo3DPoint(msg, i, 0, &p);

        x[i] = p.x;
        y[i] = p.y;
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "send_cone_coordinate");
    ros::NodeHandle scan;
    ros::NodeHandle pub;

    ros::Subscriber lidar_scan = scan.subscribe("lidar/cones", 1, scanCallBack);
    tf2_ros::Buffer tfBuffer;
    tf2_ros::TransformListener tfListener(tfBuffer);
    ros::Publisher vis_pub = pub.advertise<visualization_msgs::MarkerArray>("visualization_marker_array", 1);

    ros::Rate rate(10);

    while (ros::ok()) {
        geometry_msgs::Point32 point;
        visualization_msgs::MarkerArray marker;
        visualization_msgs::Marker mark;
        geometry_msgs::TransformStamped TF;
        tf::TransformListener Speed;
        geometry_msgs::Twist Twist;

        try {
            TF = tfBuffer.lookupTransform("map", "gotthard/base_link", ros::Time(0));
        } catch (tf2::TransformException &ex) {
            ROS_WARN("WARNING [%s]\n", ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        for (int i = 0; i < amount; i++) {
            point.x = x[i];
            point.y = y[i];

            Marker(&mark, point.x, point.y, i, -1);

            marker.markers.push_back(mark);
        }

        /*for(int i = amount; i<50; i++)
        {
            point.x = 0;
            point.y = 0;

            Marker(&mark, point.x, point.y, i, -1);

            marker.markers.push_back(mark);
        }*/

        vis_pub.publish(marker);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
