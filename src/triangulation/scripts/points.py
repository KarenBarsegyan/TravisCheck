class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def theSame(self, p):
        if (p.x == self.x) & (p.y == self.y):
            return 1
        else:
            return 0