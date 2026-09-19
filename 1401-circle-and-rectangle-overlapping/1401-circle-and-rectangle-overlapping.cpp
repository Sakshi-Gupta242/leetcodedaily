class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        //rectangle ka closest x- coordinate
        int closestX = max(x1,min(xCenter,x2));
        
        //rectangle ka closest y- coordinate
        int closestY = max(y1,min(yCenter,y2));

        //center se closest point ka difference
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        //distance squared <= radius squared
        return dx*dx +dy*dy <= radius*radius;
    }
};