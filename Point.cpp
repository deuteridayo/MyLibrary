struct Point {
    long long x, y; int quad;
    Point(long long X, long long Y) {
        x = X;
        y = Y;
        quad = getQuad();
    }
    int getQuad() {
        if(x >= 0) {
            if(y >= 0) return 1;
            else return 4;
        } else {
            if(y >= 0) return 2;
            else return 3;
        }
    }
};

bool operator<(const Point &left, const Point &right) {
    if(left.quad == right.quad) {
        return left.y * right.x < left.x * right.y;
    } else {
        return left.quad < right.quad;
    }
}