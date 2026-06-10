#include<stdio.h>
#include<stdlib.h>

#define WIDTH 80
#define HEIGHT 24

#define EMPTY '_'
#define PIXEL '*'


char picture[HEIGHT][WIDTH];
void clearPicture()
{
    int i,j;
    for(i=0;i<HEIGHT;i++)
        {
            for(j=0;j<WIDTH;j++)
                {
                    picture[i][j]=EMPTY;

}
        }
}
void displayPicture()
{
    int i,j;
for(i=0;i<HEIGHT;i++)
{
for(j=0;j<WIDTH;j++)
{
printf("%c", picture[i][j]);
}
printf("\n");
}
}
void setPixel(int x, int y)
{
    if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT)
{
picture[y][x]=PIXEL;
}
}
void drawLine(int x1,int y1,int x2,int y2)
{
int dx=abs(x2-x1);
int dy=abs(y2-y1);
int steps=(dx>dy)?dx:dy;
if(steps==0)
{
setPixel(x1,y1);
return;
}
float xInc=(float)(x2-x1)/steps;
float yInc=(float)(y2-y1)/steps;
float x=x1;
float y=y1;
int i;
for(i=0;i<=steps;i++)
{
setPixel((int)(x+0.5), (int)(y+0.5));
x+=xInc;
y+=yInc;
}
}
void drawRectangle(int x1,int y1,int x2,int y2)
{
    drawLine(x1, y1, x2, y1);
drawLine(x2, y1, x2, y2);
drawLine(x2, y2, x1, y2);
drawLine(x1, y2, x1, y1);
}
void drawCircle(int cX, int cy, int radius)
{
    int x,y;
for(x=-radius;x<=radius;x++)
{
for(y=-radius;y<=radius;y++)
{
int d=x*x+y*y;
int r=radius*radius;
if(d>=r - radius && d<=r+radius)
{
setPixel(cX + x,cy + y);
}
}
}
}
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    drawLine(x1, y1, x2, y2);
drawLine(x2, y2, x3, y3);
drawLine(x3, y3, x1, y1);
}
int main()
{
    int choice;
clearPicture();
printf("2D Graphics Editor\n");
printf("Canvas size: %d x %d\n", WIDTH, HEIGHT);
printf("Use coordinates x y.\n");
printf("x range: 0 to %d\n", WIDTH - 1);
printf("y range: 0 to %d\n", HEIGHT - 1);
while (1) {
        printf("\nMenu\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Circle\n");
        printf("4. Draw Triangle\n");
        printf("5. Display Picture\n");
        printf("6. Clear Picture\n");
printf("7. Modify Picture\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        if (choice == 1) {
            int x1, y1, x2, y2;

            printf("Enter x1 y1 x2 y2: ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            drawLine(x1, y1, x2, y2);
        }
        else if (choice == 2) {
            int x1, y1, x2, y2;

            printf("Enter top-left x y and bottom-right x y: ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            drawRectangle(x1, y1, x2, y2);
        }
        else if (choice == 3) {
            int cx, cy, radius;

            printf("Enter center x y and radius: ");
            scanf("%d %d %d", &cx, &cy, &radius);

            drawCircle(cx, cy, radius);
        }
        else if (choice == 4) {
            int x1, y1, x2, y2, x3, y3;

            printf("Enter x1 y1 x2 y2 x3 y3: ");
            scanf("%d %d %d %d %d %d",
                  &x1, &y1, &x2, &y2, &x3, &y3);

            drawTriangle(x1, y1, x2, y2, x3, y3);
        }
        else if (choice == 5) {
    printf("The picture is:\n");
    displayPicture();
}
else if (choice == 6) {
    clearPicture();
    printf("Picture cleared.\n");
}
    else if (choice == 7) {
    int x1, y1, x2, y2;

    clearPicture();

    printf("Enter new line coordinates x1 y1 x2 y2: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    drawLine(x1, y1, x2, y2);

    printf("Picture modified.\n");
}
else if(choice == 0)
{
    printf("Exiting program.\n");
    break;
}
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
