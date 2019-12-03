#!/usr/bin/env python
from delaunay import delaunay
from points import point
import rospy
from visualization_msgs.msg import MarkerArray, Marker
from geometry_msgs.msg import PolygonStamped, Point32, Polygon

def CallBack(data):
    points = []

    for i in range(len(data.markers)):
        points.append(point(data.markers[i].pose.position.x, data.markers[i].pose.position.y))

    delaun = delaunay(points)
    pointsForRos = []
    rate = rospy.Rate(10)
    points.sort(key=lambda p: p.x)
    for i in range(0, len(points)):
        for j in range(i + 1, len(points)):
            if points[i].theSame(points[j]):
                points.remove(points[j])

    if len(points) >= 3:
        lines = Marker()
        lines.header.frame_id = "gotthard/base_link"
        lines.header.stamp = rospy.Time.now()
        lines.ns = "points_and_lines"
        lines.action = Marker.ADD
        lines.pose.orientation.w = 1.0;
        lines.id = 0
        lines.type = Marker.LINE_LIST
        lines.scale.x = 0.1
        pointsForRos = delaun.triangulate(points)
        #print("num of points ", len(pointsForRos))
        for i in range(0, len(pointsForRos), 3):
            lines.points.append(Point32(x=pointsForRos[i].x, y=pointsForRos[i].y, z=0))
            lines.points.append(Point32(x=pointsForRos[i+1].x, y=pointsForRos[i+1].y, z=0))
            lines.points.append(Point32(x=pointsForRos[i + 1].x, y=pointsForRos[i + 1].y, z=0))
            lines.points.append(Point32(x=pointsForRos[i+2].x, y=pointsForRos[i+2].y, z=0))
            lines.points.append(Point32(x=pointsForRos[i + 2].x, y=pointsForRos[i + 2].y, z=0))
            lines.points.append(Point32(x=pointsForRos[i].x, y=pointsForRos[i].y, z=0))
            #rospy.sleep(1)
        lines.color.r = 1
        lines.color.a = 1

        pub.publish(lines)

def Talker():
    rospy.init_node('Delon')
    rospy.Subscriber('visualization_marker_array', MarkerArray, CallBack)

    rospy.spin()

if __name__ == '__main__':
    try:
        pub = rospy.Publisher('visualization_marker', Marker, queue_size=1)
        Talker()
    except rospy.ROSInterruptException:
        pass
