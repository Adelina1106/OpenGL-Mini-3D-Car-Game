#include "lab_m1/tema2/tema2.h"
#include "lab_m1/tema2/transform3D_tema.h"
#include "lab_m1/tema2/lab_camera.h"

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#define M_PI 3.1415

using namespace std;
using namespace m1;

Mesh* CreatePlane(
    const std::string& name,
    float length,
    glm::vec3 center,
    glm::vec3 color,
    bool fill)
{
    float dist = 0.07;
    glm::vec3 leftCorner = center;
    leftCorner.x = center.x - length / 2;
    leftCorner.z = center.z - length / 2;
       
    int line = length / dist + 1;
    int count = line * line;
    float y = 0;
    float x, z;
    std::vector<VertexFormat> vertices;
    vertices.push_back(leftCorner);
    for (int i = 0; i < count; i++) {
        vertices.push_back(VertexFormat(glm::vec3(leftCorner.x + i % line * dist, center.y, leftCorner.z + i / line * dist), color));
    }
    Mesh* sphere = new Mesh(name);
    std::vector<unsigned int> indices;
    for (int i = 1; i < count - line; i++) {
        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(line + i);

        indices.push_back(line + i);
        indices.push_back(line + i + 1);
        indices.push_back(i + 1);
    }
    if (!fill) {
        sphere->SetDrawMode(GL_LINE_LOOP);
    }
    sphere->InitFromData(vertices, indices);
    return sphere;
}

Mesh* tema2::CreateTrack(
    const std::string& name,
    glm::vec3 color,
    bool fill)
{
    pointsOfTrack;
    pointsOfTrack.push_back(glm::vec3(-6, 0, -4)); //A1
    pointsOfTrack.push_back(glm::vec3(-4, 0, -4)); //B1
    pointsOfTrack.push_back(glm::vec3(-2, 0, -4));//C1
    pointsOfTrack.push_back(glm::vec3(0,0, -4)); //A
    pointsOfTrack.push_back(glm::vec3(0.894f,0, -4.442f)); //E1
    pointsOfTrack.push_back(glm::vec3(1.487f,0,  -4.998f)); //F1
    pointsOfTrack.push_back(glm::vec3(2.265f,0,  -5.258f)); //G1
    pointsOfTrack.push_back(glm::vec3(3.117f, 0, -5.035f));//H1
    pointsOfTrack.push_back(glm::vec3(3.636f, 0, -4.442f)); //I1
    pointsOfTrack.push_back(glm::vec3(4.377f, 0, -4.072f)); //J1
    pointsOfTrack.push_back(glm::vec3(5.526f, 0, -3.998f));// K1
    pointsOfTrack.push_back(glm::vec3(6.341, 0, -4.035f)); //L1
    pointsOfTrack.push_back(glm::vec3(6.934f, 0, -3.442f));//M1
    pointsOfTrack.push_back(glm::vec3(7.304f, 0, -2.701f)); //N1
    pointsOfTrack.push_back(glm::vec3(8.342f, 0, -2.293f));//O1
    pointsOfTrack.push_back(glm::vec3(9.676f, 0, -2.293f)); // P1
    pointsOfTrack.push_back(glm::vec3(10.842f, 0, -1.997f)); //Q1
    pointsOfTrack.push_back(glm::vec3(11.788f, 0, -1.07f)); //R1
    pointsOfTrack.push_back(glm::vec3(14.448f, 0, 1.859f)); //T1
    pointsOfTrack.push_back(glm::vec3(14.447f, 0, 2.891f)); //U1
    pointsOfTrack.push_back(glm::vec3(13.862f, 0, 3.847f)); //V1
    pointsOfTrack.push_back(glm::vec3(12.788f, 0, 4.463f)); //W1
    pointsOfTrack.push_back(glm::vec3(11.715f, 0, 5.423f)); //V1'
    pointsOfTrack.push_back(glm::vec3(10.641f, 0, 6.211f)); //W1'
    pointsOfTrack.push_back(glm::vec3(9.49f, 0, 7.081f)); //Z1
    pointsOfTrack.push_back(glm::vec3(8.564f, 0, 7.6f)); //A2
    pointsOfTrack.push_back(glm::vec3(8, 0, 8)); //B2
    pointsOfTrack.push_back(glm::vec3(7.082f, 0, 8.156f)); //C2
    pointsOfTrack.push_back(glm::vec3(6.51, 0, 8.127f)); //D1
    pointsOfTrack.push_back(glm::vec3(6.181f, 0, 7.786f)); //E2
    pointsOfTrack.push_back(glm::vec3(6.146f, 0, 7.198f)); //F2
    pointsOfTrack.push_back(glm::vec3(6.580f, 0, 6.728f)); //G2
    pointsOfTrack.push_back(glm::vec3(7.378f, 0, 6.599f)); //H2
    pointsOfTrack.push_back(glm::vec3(7.967f, 0, 6.493f)); //I2
    pointsOfTrack.push_back(glm::vec3(8.473f, 0, 6.082f)); //J2
    pointsOfTrack.push_back(glm::vec3(8.786f, 0, 5.3f)); //K2
    pointsOfTrack.push_back(glm::vec3(9.117f, 0, 3.239f)); //M2
    pointsOfTrack.push_back(glm::vec3(9.053f, 0, 2.438f)); //N2
    pointsOfTrack.push_back(glm::vec3(8.818f, 0, 2.021f)); //i
    pointsOfTrack.push_back(glm::vec3(8.466f, 0, 1.797f)); //O2
    pointsOfTrack.push_back(glm::vec3(8.208f, 0, 1.765f)); //P2
    pointsOfTrack.push_back(glm::vec3(7.675f, 0, 1.914f)); //Q2
    pointsOfTrack.push_back(glm::vec3(7.408f, 0, 2.203f)); //R2
    pointsOfTrack.push_back(glm::vec3(7.063f, 0, 2.573f)); //S2
    pointsOfTrack.push_back(glm::vec3(6.493f, 0, 2.792f)); //T2
    pointsOfTrack.push_back(glm::vec3(5.866f, 0, 2.398f)); //F5
    pointsOfTrack.push_back(glm::vec3(5.488f, 0, 1.523f)); //G5
    pointsOfTrack.push_back(glm::vec3(4.853f, 0, -0.452f)); //I5
    pointsOfTrack.push_back(glm::vec3(4.571f, 0, -1.286f)); //V4
    pointsOfTrack.push_back(glm::vec3(4.317f, 0, -1.723f)); //W4
    pointsOfTrack.push_back(glm::vec3(3.975f, 0, -1.864f)); //K4
    pointsOfTrack.push_back(glm::vec3(3.557f, 0, -1.740f)); //J5
    pointsOfTrack.push_back(glm::vec3(3.371f, 0, -1.431f)); //M5
    pointsOfTrack.push_back(glm::vec3(3.228f, 0, -0.811f)); //N5
    pointsOfTrack.push_back(glm::vec3(3.043f, 0, 0.337f)); //O5
    pointsOfTrack.push_back(glm::vec3(3.006f, 0, 1.782f)); //L5
    pointsOfTrack.push_back(glm::vec3(2.82f, 0, 2.671f)); //U4
    pointsOfTrack.push_back(glm::vec3(2.413f, 0, 4.302f)); //A3
    pointsOfTrack.push_back(glm::vec3(1.635f, 0, 6.97f));//D2
    pointsOfTrack.push_back(glm::vec3(1.25f, 0, 7.723f)); //E5
    pointsOfTrack.push_back(glm::vec3(0.667f, 0, 7.967f)); //G3
    pointsOfTrack.push_back(glm::vec3(0.153f, 0, 7.893f)); //A
    pointsOfTrack.push_back(glm::vec3(-0.283f, 0, 7.564f)); //B
    pointsOfTrack.push_back(glm::vec3(-0.51f, 0, 7.01f)); //I3
    pointsOfTrack.push_back(glm::vec3(-0.31f, 0, 6.262f)); //J3
    pointsOfTrack.push_back(glm::vec3(0.31f, 0, 4.491f));//L3
    pointsOfTrack.push_back(glm::vec3(1.242f, 0, 1.833f));//O3
    pointsOfTrack.push_back(glm::vec3(1.444f, 0, 1.415f));//F
    pointsOfTrack.push_back(glm::vec3(1.487f, 0, 0.982f));//R3
    pointsOfTrack.push_back(glm::vec3(1.227f, 0, 0.607f));//S3
    pointsOfTrack.push_back(glm::vec3(0.679f, 0, 0.506f));//C
    pointsOfTrack.push_back(glm::vec3(0.160f, 0, 0.795f));//D
    pointsOfTrack.push_back(glm::vec3(-0.228f, 0, 1.372f));//E
    pointsOfTrack.push_back(glm::vec3(-0.56f, 0, 2.041f));//U2
    pointsOfTrack.push_back(glm::vec3(-1.681f, 0, 3.82f));//W2
    pointsOfTrack.push_back(glm::vec3(-2.477f, 0, 4.452f));//Z3
    pointsOfTrack.push_back(glm::vec3(-3.515f, 0, 4.783f));//A4
    pointsOfTrack.push_back(glm::vec3(-4.553f, 0, 5.043f));//B4
    pointsOfTrack.push_back(glm::vec3(-5.66f, 0, 5.374f));//D4
    pointsOfTrack.push_back(glm::vec3(-6.752f, 0, 5.609f));//C5
    pointsOfTrack.push_back(glm::vec3(-7.734f, 0, 5.59f));//F4
    pointsOfTrack.push_back(glm::vec3(-8.476f, 0, 5.045f));//G4
    pointsOfTrack.push_back(glm::vec3(-8.785f, 0, 4.108f));//H3
    pointsOfTrack.push_back(glm::vec3(-8.545f, 0, 3.273f));//I4
    pointsOfTrack.push_back(glm::vec3(-7.824f, 0, 2.661f));//J4
    pointsOfTrack.push_back(glm::vec3(-6.825f, 0, 2.587f));//K3
    pointsOfTrack.push_back(glm::vec3(-5.627f, 0, 3.042f));//L4
    pointsOfTrack.push_back(glm::vec3(-4.59f, 0, 3.005f));//M4
    pointsOfTrack.push_back(glm::vec3(-3.663f, 0, 2.523f));//N4
    pointsOfTrack.push_back(glm::vec3(-2.885f, 0, 2.004f));//O4
    pointsOfTrack.push_back(glm::vec3(-1.744f, 0, 0.7675f));//Q3
    pointsOfTrack.push_back(glm::vec3(-1.581f, 0, 0.067f));//R4
    pointsOfTrack.push_back(glm::vec3(-1.552f, 0, -0.698f));//S4
    pointsOfTrack.push_back(glm::vec3(-1.996f, 0, -1.33f));//T3
    pointsOfTrack.push_back(glm::vec3(-3.144f, 0, -1.774f));//U3
    pointsOfTrack.push_back(glm::vec3(-4.404f, 0, -1.774f));//V3
    pointsOfTrack.push_back(glm::vec3(-5.334f, 0, -1.734f));//W3
    pointsOfTrack.push_back(glm::vec3(-5.954f, 0, -1.634f));//Z4
    pointsOfTrack.push_back(glm::vec3(-6.628f, 0, -1.774f));//B5
    pointsOfTrack.push_back(glm::vec3(-7.022f, 0, -2.275f));//C4
    pointsOfTrack.push_back(glm::vec3(-7.02f, 0, -3.145f));//D3
    pointsOfTrack.push_back(glm::vec3(-6.665f, 0, -3.627f));//E4

    pointsOfTrack.push_back(glm::vec3(-6, 0, -4)); //A1
    pointsOfTrack.push_back(glm::vec3(-6, 0, -4)); //A1


    for (int i = 0; i < pointsOfTrack.size(); i++)
    {
        pointsOfTrack.at(i).x *= 2;
        pointsOfTrack.at(i).z *= 2;
    }

    float distOut = 0.6f;
    float distIn = 0.6f;
    float distInLine = 0.01f;
    float dist = 0.001f;
    float distObstacol = 0.2f;
    int triangles = 1;
    int lastPoint = 0;
    int element;
    float bigger = true;
    float Xdistance = 0, Zdistance = 0;
    float panta, nOut, nIn, nObs, nOutLine, nInLine, pantaLine;
    for (int i = 0; i < pointsOfTrack.size() - 1; i++) {
        glm::vec3 D = normalize(pointsOfTrack.at(i + 1) - pointsOfTrack.at(i));
        glm::vec3 UP = normalize(glm::vec3(0, 1, 0));
        glm::vec3 P = normalize(glm::cross(D, UP));
        glm::vec3 newInObs = pointsOfTrack.at(i) + distObstacol * P;
        Obstacol.push_back(glm::vec3(newInObs.x, 0, newInObs.z));

        element = outPointsOfTrack.size() - 1;
        if (i > 0) {
            glm::vec3 newD = normalize(pointsOfTrack.at(i) - pointsOfTrack.at(i - 1)); 
            glm::vec3 newUP = normalize(glm::vec3(0, 1, 0));
            glm::vec3 newP = normalize(glm::cross(newD, newUP));
            glm::vec3 newOutPoint = pointsOfTrack.at(i) + distOut * newP;
            glm::vec3 newInPoint = pointsOfTrack.at(i) - distIn * newP;
            glm::vec3 newInPointLine = pointsOfTrack.at(i) - distInLine * newP;
            glm::vec3 newOutPointLine = pointsOfTrack.at(i) + distInLine * newP;
            panta = (double)(newOutPoint.z - outPointsOfTrack.at(lastPoint).z) /
                (double)(newOutPoint.x - outPointsOfTrack.at(lastPoint).x);
            pantaLine = (double)(newOutPointLine.z - outPointsOfLine.at(lastPoint).z) /
                (double)(newOutPointLine.x - outPointsOfLine.at(lastPoint).x);
            nOut = newOutPoint.z - (double)panta * newOutPoint.x;
            nIn = newInPoint.z - (double)panta * newInPoint.x;
            nInLine = newInPointLine.z - (double)pantaLine * newInPointLine.x;
            nOutLine = newOutPointLine.z - (double)pantaLine * newOutPointLine.x;
            Xdistance = std::min(abs(newInPoint.x - inPointsOfTrack.at(lastPoint).x), abs(newOutPoint.x - outPointsOfTrack.at(lastPoint).x));
            Zdistance = std::min(abs(newInPoint.z - inPointsOfTrack.at(lastPoint).z), abs(newOutPoint.z - outPointsOfTrack.at(lastPoint).z));
            if (Xdistance > Zdistance) {
                triangles = (int)(Xdistance / dist);
                if (newOutPoint.x > outPointsOfTrack.at(lastPoint).x)
                    bigger = true;
                else bigger = false;
                for (int t = 0; t < triangles; t++) {
                    if (bigger) {
                        double zNewVertexOut = panta * (outPointsOfTrack.at(lastPoint).x + dist * t) + nOut;
                        double zNewVertexIn = panta * (inPointsOfTrack.at(lastPoint).x + dist * t) + nIn;
                        double zNewVertexInLine = pantaLine * (inPointsOfLine.at(lastPoint).x + dist * t) + nOutLine;
                        double zNewVertexOutLine = pantaLine * (outPointsOfLine.at(lastPoint).x + dist * t) + nInLine;
                        outPointsOfTrack.push_back(glm::vec3(outPointsOfTrack.at(lastPoint).x + (double)dist * (double)t, 0, zNewVertexOut));
                        inPointsOfTrack.push_back(glm::vec3(inPointsOfTrack.at(lastPoint).x + (double)dist * (double)t, 0, zNewVertexIn));
                        outPointsOfLine.push_back(glm::vec3(outPointsOfLine.at(lastPoint).x + (double)dist * (double)t, 0, zNewVertexOutLine));
                        inPointsOfLine.push_back(glm::vec3(inPointsOfLine.at(lastPoint).x + (double)dist * (double)t, 0, zNewVertexInLine));
                    }
                    else {
                        double zNewVertexOut = (double)panta * (outPointsOfTrack.at(lastPoint).x - dist * (double)t) + nOut;
                        double zNewVertexIn = (double)panta * (inPointsOfTrack.at(lastPoint).x - dist * (double)t) + nIn;
                        double zNewVertexOutLine = (double)pantaLine * (outPointsOfLine.at(lastPoint).x - dist * (double)t) + nOutLine;
                        double zNewVertexInLine = (double)pantaLine * (inPointsOfLine.at(lastPoint).x - dist * (double)t) + nInLine;
                        outPointsOfTrack.push_back(glm::vec3(outPointsOfTrack.at(lastPoint).x - dist * (double)t, 0, zNewVertexOut));
                        inPointsOfTrack.push_back(glm::vec3(inPointsOfTrack.at(lastPoint).x - dist * (double)t, 0, zNewVertexIn));
                        outPointsOfLine.push_back(glm::vec3(outPointsOfLine.at(lastPoint).x - (double)dist * (double)t, 0, zNewVertexOutLine));
                        inPointsOfLine.push_back(glm::vec3(inPointsOfLine.at(lastPoint).x - (double)dist * (double)t, 0, zNewVertexInLine));
                    }
                }
            }
            else {
                triangles = (int)(Zdistance / dist);
                if (newOutPoint.z > outPointsOfTrack.at(lastPoint).z)
                    bigger = true;
                else bigger = false;
                for (int t = 0; t < triangles; t++) {
                    if (bigger) {
                        float xNewVertexOut = (outPointsOfTrack.at(lastPoint).z + dist * (double)t - nOut) / (double)panta;
                        float xNewVertexIn = (inPointsOfTrack.at(lastPoint).z + dist * (double)t - nIn) / (double)panta;
                        float xNewVertexOutLine = (outPointsOfLine.at(lastPoint).z + dist * (double)t - nOutLine) / (double)pantaLine;
                        float xNewVertexInLine = (inPointsOfLine.at(lastPoint).z + dist * (double)t - nInLine) / (double)pantaLine;
                        outPointsOfTrack.push_back(glm::vec3(xNewVertexOut, 0, outPointsOfTrack.at(lastPoint).z + dist * (double)t));
                        inPointsOfTrack.push_back(glm::vec3(xNewVertexIn, 0, inPointsOfTrack.at(lastPoint).z + dist * (double)t));
                        outPointsOfLine.push_back(glm::vec3(xNewVertexOutLine, 0, outPointsOfLine.at(lastPoint).z + dist * (double)t));
                        inPointsOfLine.push_back(glm::vec3(xNewVertexInLine, 0, inPointsOfLine.at(lastPoint).z + dist * (double)t));
                    }
                    else {
                        float xNewVertexOut = (outPointsOfTrack.at(lastPoint).z - dist * (double)t - nOut) / (double)panta;
                        float xNewVertexIn = (inPointsOfTrack.at(lastPoint).z - dist * (double)t - nIn) / (double)panta;
                        float xNewVertexOutLine = (outPointsOfLine.at(lastPoint).z - dist * (double)t - nOutLine) / (double)pantaLine;
                        float xNewVertexInLine = (inPointsOfLine.at(lastPoint).z - dist * (double)t - nInLine) / (double)pantaLine;
                        outPointsOfTrack.push_back(glm::vec3(xNewVertexOut, 0, outPointsOfTrack.at(lastPoint).z - (double)dist * (double)t));
                        inPointsOfTrack.push_back(glm::vec3(xNewVertexIn, 0, inPointsOfTrack.at(lastPoint).z - dist * (double)t));
                        outPointsOfLine.push_back(glm::vec3(xNewVertexOutLine, 0, outPointsOfLine.at(lastPoint).z - (double)dist * (double)t));
                        inPointsOfLine.push_back(glm::vec3(xNewVertexInLine, 0, inPointsOfLine.at(lastPoint).z - dist * (double)t));
                    }
                }
            }
        }
        outPointsOfTrack.push_back(pointsOfTrack.at(i) + distOut * P);
        inPointsOfTrack.push_back(pointsOfTrack.at(i) - distIn * P);
        outPointsOfLine.push_back(pointsOfTrack.at(i) + distInLine * P);
        inPointsOfLine.push_back(pointsOfTrack.at(i) - distInLine * P);
        lastPoint = outPointsOfTrack.size() - 1;
        Obstacol.push_back(glm::vec3(pointsOfTrack.at(i).x + distObstacol * P.x, 0.05, pointsOfTrack.at(i).z + distObstacol * P.z));

    }

    std::vector<VertexFormat> vertices;
    for (int i = 0; i < outPointsOfTrack.size(); i++)
        vertices.push_back(VertexFormat(outPointsOfTrack.at(i), color));
    for (int i = 0; i < inPointsOfTrack.size(); i++)
        vertices.push_back(VertexFormat(inPointsOfTrack.at(i), color));

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices;
    for (int i = 0; i < outPointsOfTrack.size() - 1; i++) {
        indices.push_back(outPointsOfTrack.size() + i);
        indices.push_back(outPointsOfTrack.size() + i + 1);
        indices.push_back(i + 1);

        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(outPointsOfTrack.size() + i);
    }
    indices.push_back(0);
    indices.push_back(outPointsOfTrack.size() - 2);
    indices.push_back(outPointsOfTrack.size());

    indices.push_back(0);
    indices.push_back(outPointsOfTrack.size());
    indices.push_back(outPointsOfTrack.size() + outPointsOfTrack.size() - 2);

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        square->SetDrawMode(GL_TRIANGLES);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* tema2::CreateLine(
    const std::string& name,
    glm::vec3 color,
    bool fill) {

    std::vector<VertexFormat> vertices;
    for (int i = 0; i < outPointsOfLine.size(); i++)
        vertices.push_back(VertexFormat(outPointsOfLine.at(i), color));
    for (int i = 0; i < inPointsOfLine.size(); i++)
        vertices.push_back(VertexFormat(inPointsOfLine.at(i), color));

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices;
    for (int i = 0; i < outPointsOfLine.size() - 1; i++) {
        indices.push_back(outPointsOfLine.size() + i);
        indices.push_back(outPointsOfLine.size() + i + 1);
        indices.push_back(i + 1);

        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(outPointsOfLine.size() + i);
    }
    indices.push_back(0);
    indices.push_back(outPointsOfLine.size() - 2);
    indices.push_back(outPointsOfLine.size());

    indices.push_back(0);
    indices.push_back(outPointsOfLine.size());
    indices.push_back(outPointsOfLine.size() + outPointsOfLine.size() - 2);

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        square->SetDrawMode(GL_TRIANGLES);
    }

    square->InitFromData(vertices, indices);
    return square;

}

tema2::tema2()
{
}


tema2::~tema2()
{
}


void tema2::Init()
{
    srand((unsigned)time(NULL));
    carRotateOY = 0;
    bool status = false;
    carPos = glm::vec3(-1.7f, 0.075, 5.5);
    counter = 0;
    bottom = -4.f;
    top = 4.f;
    right = 4.f;
    left = -4.f;
    renderCameraTarget = false;
    mini = false;
    inTrack = true;
    
    FoV = RADIANS(45);
    camera = new implemented::MyCamera();
    cameraPos = glm::vec3(-2.2, 0.3f, carPos.z + camera->distanceToTarget);
    cameraCenter = glm::vec3(-1.7f, 0.3f, 5.5f);
    cameraUp = glm::vec3(-1.7, 1, 5.5f);
    camera->Set(cameraPos, cameraCenter, glm::vec3(0, 1, 0));
    camera->RotateThirdPerson_OY(-0.32);

    miniCamera = new implemented::MyCamera();
    cameraPos = glm::vec3(-1.7f, 3, 5.5);
    cameraCenter = glm::vec3(-1.7, 0, 5.5f);
    cameraUp = glm::vec3(-1.7, 1, 5.5f);
    miniCamera->Set(cameraPos, cameraCenter, cameraUp);
    miniCamera->RotateThirdPerson_OY(-M_PI);
    miniCamera->RotateThirdPerson_OY(-M_PI / 13);
    
    glm::ivec2 resolution = window->GetResolution();
    miniViewportArea = ViewportArea(window->GetResolution().x / 5 * 3.5f, 50, resolution.x / 4.f, resolution.y / 4.f);

    {
        Shader* shader1 = new Shader("Shader");
        shader1->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
        shader1->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader1->CreateAndLink();
        shaders[shader1->GetName()] = shader1;
    }

    {
        Shader* shader2 = new Shader("TreeShader");
        shader2->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "TreeVertexShader.glsl"), GL_VERTEX_SHADER);
        shader2->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader2->CreateAndLink();
        shaders[shader2->GetName()] = shader2;
    }

    {
        Shader* shader4 = new Shader("SkyShader");
        shader4->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "SkyVertexShader.glsl"), GL_VERTEX_SHADER);
        shader4->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader4->CreateAndLink();
        shaders[shader4->GetName()] = shader4;
    }

    {
        Shader* shader3 = new Shader("ObsShader");
        shader3->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "ObsVertexShader.glsl"), GL_VERTEX_SHADER);
        shader3->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "tema2", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
        shader3->CreateAndLink();
        shaders[shader3->GetName()] = shader3;
    }


    Mesh* track = CreateTrack("track",glm::vec3(0.36f, 0.25f, 0.2f), true);
    AddMeshToList(track);

    Mesh* line = CreateLine("line", glm::vec3(1, 1, 1), true);
    AddMeshToList(line);

    int noOfObstacles = 30;
    for (int i = 0; i < noOfObstacles; i++) {
        int na = rand();
        int aux = na % (Obstacol.size());
        obstacole.push_back(aux);
        obstacolePos.push_back(Obstacol.at(aux));
        obsColors.push_back(glm::vec3(1 / (rand() % 5 + 1) + 0.1, 1 / (rand() % 5 + 1) + 0.1, (1 / (rand() % 5 + 1))));
    }

    int noOfBonus = 10;
    for (int i = 0; i < noOfBonus; i++) {
        int na = rand();
        int aux = na % (Obstacol.size());
        bonusPos.push_back(glm::vec3(Obstacol.at(aux).x, Obstacol.at(aux).y, Obstacol.at(aux).z));
    }


    Mesh* plane = CreatePlane("plane", 120, glm::vec3(0, -0.01f, 0), glm::vec3(0.2f, 0.36f, 0.23f), true);
    AddMeshToList(plane);

    Mesh* sky = new Mesh("sphere");
    sky->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
    meshes[sky->GetMeshID()] = sky;

    Mesh* mesh3 = new Mesh("jeep");
    mesh3->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "18544_Ultracompact_Car_V1.obj");
    meshes[mesh3->GetMeshID()] = mesh3;

    Mesh* mesh4 = new Mesh("tree");
    mesh4->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "tree1.obj");
    meshes[mesh4->GetMeshID()] = mesh4;


    Mesh* mesh5 = new Mesh("tree1");
    mesh5->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "tree.obj");
    meshes[mesh5->GetMeshID()] = mesh5;

    Mesh* mesh6 = new Mesh("bonus");
    mesh6->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "estrellica.obj");
    meshes[mesh6->GetMeshID()] = mesh6;

    Mesh* mesh7 = new Mesh("bench");
    mesh7->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "Bench_HighRes.obj");
    meshes[mesh7->GetMeshID()] = mesh7;

    int trees = 350;
    for (int i = 0; i < trees ; i++) {
        long int random = rand() ^ (rand() << (rand() % 10 + 1));
        int ind = random % (outPointsOfTrack.size() - 1);
        float auxX = inPointsOfTrack.at(ind).x - outPointsOfTrack.at(ind).x;
        float auxZ = inPointsOfTrack.at(ind).z - outPointsOfTrack.at(ind).z;
        glm::vec3 direction;
        if (i < trees / 2) {
            direction = inPointsOfTrack.at(ind) - inPointsOfLine.at(ind);
            treesPos.push_back(glm::vec3(inPointsOfTrack.at(ind).x + 0.6 * direction.x, 0, inPointsOfTrack.at(ind).z + 0.6 * direction.z)); 
        }
        else {
            direction = outPointsOfTrack.at(ind) - outPointsOfLine.at(ind);
            treesPos.push_back(glm::vec3(outPointsOfTrack.at(ind).x + 0.6 * direction.x, 0, outPointsOfTrack.at(ind).z + 0.6 * direction.z));
        }
    }
    int aux = 50;
    for (int i = 0; i < aux; i++) {
        long int random = rand() ^ (rand() << (rand() % 10 + 1));
        int ind = random % (outPointsOfTrack.size() - 1);
        float auxX = inPointsOfTrack.at(ind).x - outPointsOfTrack.at(ind).x;
        float auxZ = inPointsOfTrack.at(ind).z - outPointsOfTrack.at(ind).z;
        glm::vec3 direction;
        if (i < aux / 2) {
            direction = inPointsOfTrack.at(ind) - inPointsOfLine.at(ind);
            benchPos.push_back(glm::vec3(inPointsOfTrack.at(ind).x + 0.6 * direction.x, 0, inPointsOfTrack.at(ind).z + 0.6 * direction.z));
        }
        else {
            direction = outPointsOfTrack.at(ind) - outPointsOfLine.at(ind);
            benchPos.push_back(glm::vec3(outPointsOfTrack.at(ind).x + 0.6 * direction.x, 0, outPointsOfTrack.at(ind).z + 0.6 * direction.z));
        }
    }


    projectionMatrix = glm::perspective(RADIANS(40), window->props.aspectRatio, 0.01f, 100.0f);
    projectionMatrixMini = glm::ortho(left, right, bottom, top, 0.0f, 100.0f);
   

}


void tema2::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, glm::vec3& obs_pos, const glm::vec3& color, const glm::vec3& secondColor)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;
    // Render an object using the specified shader and the specified position

    glUseProgram(shader->program);

    int object_color = glGetUniformLocation(shader->program, "object_color");
    glUniform3fv(object_color, 1, glm::value_ptr(color));

    int car_pos = glGetUniformLocation(shader->program, "car_position");
    glUniform3fv(car_pos, 1, glm::value_ptr(carPos));

    if (shader == shaders["ObsShader"] || shader == shaders["TreeShader"]) {
        int car_pos = glGetUniformLocation(shader->program, "obs_position");
        glUniform3fv(car_pos, 1, glm::value_ptr(obs_pos));
    }

    if (shader == shaders["TreeShader"]) {
        int car_pos = glGetUniformLocation(shader->program, "trunk_color");
        glUniform3fv(car_pos, 1, glm::value_ptr(secondColor));
    }

    if(!mini)
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    else glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(miniCamera->GetViewMatrix()));

    if(!mini)
        glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    else glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrixMini));
    
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}
bool tema2::CheckInTrack(glm::vec3 carPos, float dist) {

    for (int i = 0; i < pointsOfTrack.size() - 2; i++) {
        glm::vec3 P1 = pointsOfTrack.at(i);
        glm::vec3 P2 = pointsOfTrack.at(i + 1);
        glm::vec3 P3 = carPos;
        glm::vec3 P4 = P2 - P1;
        float norm = P4.x * P4.x  + P4.z * P4.z;
        float u = ((P3.x - P1.x)*(P2.x - P1.x) + (P3.z - P1.z)*(P2.z - P1.z)) / norm;
        float x = P1.x + u * (P2.x - P1.x);
        float z = P1.z + u * (P2.z - P1.z);
        float distance = sqrt((P3.x - x) * (P3.x - x) + (P3.z - z) * (P3.z - z));
        if (distance <= dist && ((carPos.x >= min(pointsOfTrack.at(i + 1).x, pointsOfTrack.at(i).x)
            && carPos.x <= max(pointsOfTrack.at(i + 1).x, pointsOfTrack.at(i).x)) ||
            (carPos.z >= min(pointsOfTrack.at(i + 1).z, pointsOfTrack.at(i).z)
                && carPos.z <= max(pointsOfTrack.at(i + 1).z, pointsOfTrack.at(i).z)))) {
            return true;
        }
        else if ((carPos.x == P1.x && carPos.z == P1.z) || (carPos == P2 && carPos.z == P2.z))
            return true;
    }
    return false;
}

void tema2::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

void tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    shader->Use();
    if(!mini)
        glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    else glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(miniCamera->GetViewMatrix()));

    if(!mini)
        glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    else glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrixMini));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}

void tema2::RenderScene(float deltaTimeSeconds) {
    glm::mat4 modelMatrix1 = glm::mat4(1);
    RenderSimpleMesh(meshes["plane"], shaders["Shader"], modelMatrix1,glm::vec3(0, 0, 0), glm::vec3(0.2f, 0.36f, 0.23f));

    modelMatrix1 = glm::mat4(1);
    modelMatrix1 *= transform3D_tema::Scale(100, 100, 100);
    RenderSimpleMesh(meshes["sphere"], shaders["SkyShader"], modelMatrix1, glm::vec3(0, 0, 0), glm::vec3(0.52f, 0.8f, 1));

    modelMatrix1 = glm::mat4(1);
    RenderSimpleMesh(meshes["track"], shaders["Shader"], modelMatrix1, glm::vec3(0, 0, 0), glm::vec3(0.36f, 0.25f, 0.2f));

    modelMatrix1 = glm::mat4(1);
    RenderSimpleMesh(meshes["line"], shaders["Shader"], modelMatrix1, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));

    glm::mat4 modelMatrix = glm::mat4(1);
    modelMatrix = glm::translate(modelMatrix, carPos);
    modelMatrix *= transform3D_tema::RotateOY(-4.2 / 2 + M_PI);
    modelMatrix *= transform3D_tema::RotateOY(carRotateOY);
    modelMatrix1 = glm::translate(modelMatrix, glm::vec3(0.00001, 0, 0));
    RenderSimpleMesh(meshes["jeep"], shaders["SkyShader"], modelMatrix1, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
    modelMatrix1 = glm::translate(modelMatrix, glm::vec3(0, 0, -0.00001));
    RenderSimpleMesh(meshes["jeep"], shaders["SkyShader"], modelMatrix, glm::vec3(0, 0, 0), glm::vec3(0.53f, 0.81f, 0.94f));
    float ObsSpeed = 0.6f;
    
    for (int i = 0; i < treesPos.size() - 2; i+=2) {
        if (i < treesPos.size() - 2) {
            modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, treesPos.at(i));
            modelMatrix1 = glm::mat4(1);
            if (i + 1 < treesPos.size() - 1) {
                modelMatrix1 = glm::translate(modelMatrix1, treesPos.at(i + 1));
                RenderSimpleMesh(meshes["tree1"], shaders["TreeShader"], modelMatrix1, treesPos.at(i + 1), glm::vec3(0, 0.23f, 0.19f), glm::vec3(0.26f, 0.15f, 0.05f));
            }

            RenderSimpleMesh(meshes["tree"], shaders["TreeShader"], modelMatrix, treesPos.at(i), glm::vec3(0, 0.23f, 0.19f), glm::vec3(0.26f, 0.15f, 0.05f));
        }

    }

    for (int i = 0; i < benchPos.size() - 1; i++) {
        modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, benchPos.at(i));
        if(i < benchPos.size() / 2)
            modelMatrix *= transform3D_tema::RotateOY(M_PI / 3 + M_PI );
       RenderSimpleMesh(meshes["bench"], shaders["ObsShader"], modelMatrix, benchPos.at(i), glm::vec3(0, 0, 0), glm::vec3(0.26f, 0.15f, 0.05f));


    }

    for (int i = 0; i < bonusPos.size() - 1; i++) {
        modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, bonusPos.at(i));
        modelMatrix *= transform3D_tema::RotateOY(atan(bonusPos.at(i).x / bonusPos.at(i).z));
        RenderSimpleMesh(meshes["bonus"], shaders["ObsShader"], modelMatrix, bonusPos.at(i), glm::vec3(0, 0, 1));
    }

    int size = obstacole.size() - 1;
    float rotate = 0;
    for (int i = 0; i < size; i++) {
        modelMatrix = glm::mat4(1);
        glm::vec3 pos;
        if(obstacole.at(i) < Obstacol.size() - 1)
            pos = Obstacol.at(obstacole.at(i) + 1) - Obstacol.at(obstacole.at(i));
        else pos = Obstacol.at(0) - Obstacol.at(obstacole.at(i));

        obstacolePos.at(i).x += ObsSpeed  * deltaTimeSeconds * normalize(pos).x;
        obstacolePos.at(i).z += ObsSpeed  * deltaTimeSeconds * normalize(pos).z;
        modelMatrix = glm::translate(modelMatrix, obstacolePos.at(i));
        if(obstacole.at(i) < Obstacol.size() - 1)
            if (abs(obstacolePos.at(i).x - Obstacol.at(obstacole.at(i) + 1).x) < ObsSpeed * deltaTimeSeconds  &&
                abs(obstacolePos.at(i).z - Obstacol.at(obstacole.at(i) + 1).z) < ObsSpeed * deltaTimeSeconds) {
                obstacole.at(i)++;
                if (obstacole.at(i) >= Obstacol.size() - 3)
                    obstacole.at(i) = 0;
                obstacolePos.at(i) = Obstacol.at(obstacole.at(i));
            }
        
        modelMatrix *= transform3D_tema::RotateOY(atan(pos.x / pos.z));
        modelMatrix *= transform3D_tema::RotateOY(-M_PI / 2 + M_PI);
        if (CheckInTrack(obstacolePos.at(i), 0.45f))
            RenderSimpleMesh(meshes["jeep"], shaders["ObsShader"], modelMatrix, glm::vec3(obstacolePos.at(i).x, 1, obstacolePos.at(i).z), obsColors.at(i));
        else {
            obstacole.erase(std::next(obstacole.begin(), i));
            obstacolePos.erase(std::next(obstacolePos.begin(), i));
            size--;
            i--;
        }
        
    }

}

bool tema2::CheckCars() {
    for (int i = 0; i < obstacolePos.size() - 1; i++) {
        float aux = sqrt(pow((carPos.x - obstacolePos.at(i).x), 2) + pow((carPos.y - obstacolePos.at(i).y), 2) + pow((carPos.z - obstacolePos.at(i).z), 2));
        
        if (aux <= 2 * 0.15)
            return false;
    }
    return true;
}

bool tema2::CheckBonus() {
    for (int i = 0; i < bonusPos.size() - 1; i++) {
        float aux = sqrt(pow((carPos.x - bonusPos.at(i).x), 2) + pow((carPos.z - bonusPos.at(i).z), 2));

        if (aux <= 2 * 0.11)
            return true;
    }
    return false;
}


void tema2::Update(float deltaTimeSeconds)
{
    if (myTime >= 2.5f && speed > 2 || myTime >= 2.5f  && !CheckBonus()) {
        speed = 2;
    }
    if (CheckBonus())
    {
        myTime = 0;
        speed = 4.5f;
    }
    myTime += deltaTimeSeconds;
    mini = false;
    RenderScene(deltaTimeSeconds);
    glClear(GL_DEPTH_BUFFER_BIT);

    miniViewportArea = ViewportArea(window->GetResolution().x / 5 * 3.5f, 50, window->GetResolution().x / 4.f, window->GetResolution().y / 4.f);
    glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);
    mini = true;
    RenderScene(deltaTimeSeconds);

}


void tema2::FrameEnd(){
}


void tema2::OnInputUpdate(float deltaTime, int mods)
{
    {
        float sensivityOY = 1.1f;
        if (speed == 0)
            speed = 2;
        if (window->KeyHold(GLFW_KEY_W)) {
            bool aux = CheckCars();
            int delta = 1;
            if (aux) {
                if (CheckInTrack(glm::vec3(carPos.x + delta * normalize(camera->forward).x * speed * deltaTime, 0, carPos.z + delta * normalize(camera->forward).z * speed * deltaTime), 0.45f)) {
                    camera->TranslateForward(speed * deltaTime);
                    miniCamera->Set(glm::vec3(carPos.x, 3, carPos.z), carPos, cameraUp);

                    carPos.x += normalize(camera->forward).x * speed * deltaTime;
                    carPos.z += normalize(camera->forward).z * speed * deltaTime;
                    miniCamera->RotateThirdPerson_OY(M_PI);
                    miniCamera->RotateThirdPerson_OY(-M_PI / 13);
                }
            }
        }

        if (window->KeyHold(GLFW_KEY_A)) {
            camera->RotateThirdPerson_OY(sensivityOY * deltaTime);
            carRotateOY += sensivityOY * deltaTime;
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            bool aux = CheckCars();
            if (aux) {
                if (CheckInTrack(glm::vec3(carPos.x - normalize(camera->forward).x * speed * deltaTime, 0, carPos.z - normalize(camera->forward).z * speed * deltaTime), 0.42f)) {
                    camera->TranslateForward(-speed * deltaTime);
                    miniCamera->Set(glm::vec3(carPos.x, 3, carPos.z), carPos, cameraUp);
                    carPos.x -= normalize(camera->forward).x * speed * deltaTime;
                    carPos.z -= normalize(camera->forward).z * speed * deltaTime;
                    miniCamera->RotateThirdPerson_OY(M_PI);
                    miniCamera->RotateThirdPerson_OY(-M_PI / 13);

                }
            }
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            camera->RotateThirdPerson_OY(-sensivityOY * deltaTime);
            carRotateOY -= sensivityOY * deltaTime;
            
        }
    }
}


void tema2::OnKeyPress(int key, int mods)
{
 
}


void tema2::OnKeyRelease(int key, int mods)
{

}


void tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
   
}


void tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
    // Treat mouse scroll event
}


void tema2::OnWindowResize(int width, int height)
{
    // Treat window resize event
    window->GetResolution();
}
