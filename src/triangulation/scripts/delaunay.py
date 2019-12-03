from edges import Edge
from triangles import triangle
from points import point

class delaunay:
    BLACK = (0, 0, 0)

    def __init__(self, points):
        self.pointArr = points
        self.edgeArr = []
        self.triangleArr = []
        self.pointsForRos = []
        self.superP1 = 0
        self.superP2 = 0
        self.superP3 = 0
        #self.triangulate(points)

    def superTriangle(self, points):
        maxX = points[0].x
        maxY = points[0].y
        minX = points[0].x
        minY = points[0].y

        for i in range(0, len(points)):
            if points[i].x < minX:
                minX = points[i].x
            if points[i].x > maxX:
                maxX = points[i].x
            if points[i].y < minY:
                minY = points[i].y
            if points[i].y > maxY:
                maxY = points[i].y

        dx = maxX - minX
        dy = maxY - minY
        deltaMax = max(dx, dy)
        midX = (minX + maxX) / 2
        midY = (minY + maxY) / 2
        self.superP1 = point(midX - 20 * deltaMax, midY - deltaMax)
        self.superP2 = point(midX, midY + 20 * deltaMax)
        self.superP3 = point(midX + 20 * deltaMax, midY - deltaMax)
        self.triangleArr.append(triangle(self.superP1, self.superP2, self.superP3))

    def chekDoubly(self, e):
        for i in range(0, len(e)):
            for j in range(i + 1, len(e)):
                if ((e[i].point1 == e[j].point1) & (e[i].point2 == e[j].point2)) | (
                        (e[i].point1 == e[j].point2) & (e[i].point2 == e[j].point1)):
                    e[i].isBad = 1
                    e[j].isBad = 1
                    break

    def triangulate(self, points):
        self.superTriangle(points)
        for p in points:
            for t in self.triangleArr:
                if t.circumcircleContains(p):
                    t.isBad = 1
                    self.edgeArr.append(Edge(t.point1, t.point2))
                    self.edgeArr.append(Edge(t.point2, t.point3))
                    self.edgeArr.append(Edge(t.point3, t.point1))
            self.triangleArr = [i for i in self.triangleArr if i.isBad == 0]
            self.chekDoubly(self.edgeArr)
            self.edgeArr = [i for i in self.edgeArr if i.isBad == 0]
            for e in self.edgeArr:
                self.triangleArr.append(triangle(e.point1, e.point2, p))
            self.triangleArr = [i for i in self.triangleArr if i.isBad == 0]
            self.edgeArr = []

        self.triangleArr = [i for i in self.triangleArr if not ((i.contains(self.superP1)) |
                                                                (i.contains(self.superP2)) |
                                                                (i.contains(self.superP3)))]

        for t in self.triangleArr:
            self.pointsForRos.append(point(t.point1.x, t.point1.y))
            self.pointsForRos.append(point(t.point2.x, t.point2.y))
            self.pointsForRos.append(point(t.point3.x, t.point3.y))
        return self.pointsForRos
