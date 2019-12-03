#include "ros/ros.h"
#include "sensor_msgs/PointCloud2.h"
#include "geometry_msgs/Point.h"
#include "tf2_ros/transform_listener.h"
#include "tf/transform_listener.h"
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include "geometry_msgs/PolygonStamped.h"
#include "geometry_msgs/Twist.h"
#include "vector"

void pixelTo3DPoint(const sensor_msgs::PointCloud2& pCloud, const int u_coord, const int v_coord,
                    geometry_msgs::Point* point) {
    //Convert from u (column / width), v (row/height) to position in array
    //where X,Y,Z data starts
    int array_position = v_coord*pCloud.row_step + u_coord*pCloud.point_step;

    //compute position in array where x,y,z data start
    int array_pos_x = array_position + pCloud.fields[0].offset;  // X has an offset of 0
    int array_pos_y = array_position + pCloud.fields[1].offset;  // Y has an offset of 4
    int array_pos_z = array_position + pCloud.fields[2].offset;  // Z has an offset of 8

    float X = 0.0;
    float Y = 0.0;
    float Z = 0.0;

    memcpy(&X, &pCloud.data[array_pos_x], sizeof(float));
    memcpy(&Y, &pCloud.data[array_pos_y], sizeof(float));
    memcpy(&Z, &pCloud.data[array_pos_z], sizeof(float));

    //put data into the point p
    point->x = X;
    point->y = Y;
    point->z = Z;
}

void Marker(float x, float y, int id, bool is_transperent, visualization_msgs::Marker* marker) {
    marker->header.frame_id = "gotthard/base_link";
    marker->header.stamp = ros::Time(0);
    marker->ns = "lidar_namespace";
    marker->id = id;
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
    marker->color.a = 1.0;  //Don't forget to set the alpha!
    marker->color.r = 0.0;
    marker->color.g = 1.0;
    marker->color.b = 0.0;

    if (!is_transperent) {
        marker->color.a = 0.0;
    }
}

std::vector<double> x;
std::vector<double> y;

void scanCallBack(const sensor_msgs::PointCloud2& msg) {
    geometry_msgs::Point point;

    x.clear();
    y.clear();

    for (int i = 0; i < msg.width; ++i) {
        pixelTo3DPoint(msg, i, 0, &point);

        x.push_back(point.x);
        y.push_back(point.y);
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
        geometry_msgs::TransformStamped tf;

        try {
            tf = tfBuffer.lookupTransform("map", "gotthard/base_link", ros::Time(0));
        } catch (tf2::TransformException &ex) {
            ROS_WARN("WARNING [%s]\n", ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        for (size_t i = 0; i < x.size(); ++i) {
            point.x = x[i];
            point.y = y[i];

            Marker(point.x, point.y, i, 0, &mark);

            marker.markers.push_back(mark);
        }

        vis_pub.publish(marker);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
