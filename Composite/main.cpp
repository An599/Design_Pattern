#include <iostream>
#include "GraphicObj.h"

int main()
{
    Group root("root");
    Circle c1;
    Rectangle r1;
    Triangle t1;
    root.objects.push_back(&c1);

    Group subgr("subgroup");
    subgr.objects.push_back(&r1);
    subgr.objects.push_back(&t1);

    root.objects.push_back(&subgr);
    root.draw();
