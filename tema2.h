#pragma once
#include "components/simple_scene.h"
#include "components/transform.h"
#include "lab_m1/tema2/lab_camera.h"

namespace m1
{
    class tema2 : public gfxc::SimpleScene
    {
     public:
        tema2();
        ~tema2();

        void Init() override;


        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void RenderScene(float deltaTimeSeconds);
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
        void tema2::RenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix) override;
        void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, glm::vec3& obs_pos, const glm::vec3& color = glm::vec3(1), const glm::vec3& secondColor = glm::vec3(1));
        Mesh* CreateTrack(const std::string& name, glm::vec3 color, bool fill);
        Mesh* tema2::CreateLine(const std::string& name,glm::vec3 color,bool fill);
        bool CheckCars();
        bool CheckInTrack(glm::vec3 carPos, float dist);
        bool CheckBonus();
        Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, float width, float length, glm::vec3 color, bool fill);

        // TODO(student): Class variables go here
        std::vector<glm::vec3> Obstacol;
        std::vector<int> obstacole;
        glm::vec3 position;
        glm::vec3 archer_position;
        int colour;
        std::string object;
        int counter;
        bool status;
        float x_pos, y_pos, z_pos;
        int frame;
        bool isObs = false;
        int count = 1;
        std::vector<glm::vec3> obstacolePos;
        std::vector<glm::vec3> obsColors;
        std::vector<glm::vec3> treesPos;
        std::vector<glm::vec3> bonusPos;

        implemented::MyCamera* camera, *miniCamera, *speedCamera;
        glm::vec3 cameraPos, cameraCenter, cameraUp, carPos;
        glm::mat4 projectionMatrix, projectionMatrixMini;
        bool renderCameraTarget;
        float FoV;
        float width, top, bottom, left, right;
        float carRotateOY;
        ViewportArea miniViewportArea;
        ViewportArea speedViewportArea;
        bool mini = false;
        bool speedC = false;
        float acc = 0.5, initialSpeed = 0.7f;
        std::vector<glm::vec3> pointsOfTrack;
        std::vector<glm::vec3> inPointsOfTrack;
        std::vector<glm::vec3> outPointsOfTrack;
        std::vector<glm::vec3> inPointsOfLine;
        std::vector<glm::vec3> outPointsOfLine;
        std::vector<glm::vec3> benchPos;
        bool inTrack;
        float speed = 2;
        float myTime;
        

    };
}   // namespace m1
