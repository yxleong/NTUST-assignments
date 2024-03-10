
// Standard Header For Most Programs
#include <windows.h>   
// The GL Header
#include <gl/gl.h>     
// The GL Utility Toolkit (Glut)
#include <gl/glut.h>

#include <cmath>
#include <algorithm>
#define M_PI 3.14159265358979323846

// Camera control variables
float cameraRotationAngle = 0.0f;
float cameraRotationSpeed = 0.02f;
float cameraPositionX = 0.0f;
float cameraPositionY = 0.0f;
float cameraPositionZ = 0.0f;

// Camera orientation
float cameraAzimuthAngle = 0.0f;    // rotation around the vertical axis (y-axis)
float cameraElevationAngle = 0.0f;  // rotation around the horizontal axis (x-axis)
const float mouseSensitivity = 0.6f;

void handleMouseMove(int mouseX, int mouseY) {
    static int lastMouseX = -1;
    static int lastMouseY = -1;

    if (lastMouseX == -1 && lastMouseY == -1) {
        lastMouseX = mouseX;
        lastMouseY = mouseY;
    }

    int deltaX = mouseX - lastMouseX;
    int deltaY = mouseY - lastMouseY;

    // turning left or right when standing still
    cameraAzimuthAngle += deltaX * mouseSensitivity;

    cameraElevationAngle -= deltaY * mouseSensitivity;  // looking up or down
    // prevent the camera from flipping over
    cameraElevationAngle = (std::max)(-89.0f, (std::min)(89.0f, cameraElevationAngle)); // set 90 will lead to math problem

    lastMouseX = mouseX;
    lastMouseY = mouseY;

    // request window redraw after handling input
    glutPostRedisplay();
}

float degreesToRadians(float degrees) {
    return degrees * (static_cast<float>(M_PI) / 180.0f);
}

// Create Some Everyday Functions
bool InitGL()
{
    // Enable Smooth Shading
    glShadeModel(GL_SMOOTH);
    // Black Background
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    // Depth Buffer Setup
    glClearDepth(1.0f);
    // Enables Depth Testing
    glEnable(GL_DEPTH_TEST);
    // The Type Of Depth Testing To Do	
    glDepthFunc(GL_LEQUAL);
    return TRUE;
}

void drawGrid(int size) {
    glColor3f(1.0, 1.0, 1.0); // Set grid color to white
    glBegin(GL_LINES);

    for (int i = -size; i <= size; i++) {
        // Vertical lines
        glVertex3f((float)i, 0, (float)-size);
        glVertex3f((float)i, 0, (float)size);

        // Horizontal lines
        glVertex3f((float)-size, 0, (float)i);
        glVertex3f((float)size, 0, (float)i);
    }

    glEnd();
}

void display(void)   // Create The Display Function
{
    // Clear Screen And Depth Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();		// Reset The Current Modelview Matrix

    // convert to radian
    float radAzimuth = degreesToRadians(cameraAzimuthAngle);
    float radElevation = degreesToRadians(cameraElevationAngle);

    // cos(radElevation) scales this component based on the camera's tilt
    float lookDirectionX = cos(radElevation) * sin(radAzimuth);
    // sin(radAzimuth) for the east-west directionality
    // if sin(0) = 0, no movement to the east or west
    // if sin(¦Ð/2) = 1, east
    // if sin(-¦Ð/2) or sin(3¦Ð/2) = -1, west

    // vertical axis
    float lookDirectionY = sin(radElevation);   // sin to get right angle side

    // cos(radAzimuth) for the north-south directionality
    float lookDirectionZ = cos(radElevation) * cos(radAzimuth);
    // cos(radElevation) scales this component based on the camera's tilt
    // if cos(0) = 1, full amount of the azimuth-based direction
    // if near cos(¦Ð/2) or cos(-¦Ð/2) = 0, nearly no influence when facing in the horizontal plane
        // since are looking up or looking down

    gluLookAt(cameraPositionX, cameraPositionY, cameraPositionZ, // eye/camera: camera located
        cameraPositionX + lookDirectionX, cameraPositionY + lookDirectionY, cameraPositionZ + lookDirectionZ, // center/target: camera look at
        0.0f, 1.0f, 0.0f); // up: third party perspective - make camera fixed and cannot be rotated

   /* glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -5.0);
    glutWireTeapot(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5.0, 0.0, -5.0);
    glutWireTeapot(1.0);
    glPopMatrix();*/

    drawGrid(10);

    glFlush();
    glutSwapBuffers();
}

// Create The Reshape Function (the viewport)
void ReSizeGLScene(int width, int height)
{
    if (height == 0)    // Prevent A Divide By Zero By
    {
        height = 1; // Making Height Equal One
    }
    // Reset The Current Viewport
    glViewport(0, 0, width, height);
    // Select The Projection Matrix
    glMatrixMode(GL_PROJECTION);
    // Reset The Projection Matrix
    glLoadIdentity();
    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
    glTranslatef(0, 0, -4.0f);
    // Select The Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void updateWASDQE() {
    float radAzimuth = degreesToRadians(cameraAzimuthAngle);
    float radElevation = degreesToRadians(cameraElevationAngle);

    // camera facing
    float forwardX = cos(radElevation) * sin(radAzimuth);
    float forwardY = sin(radElevation);
    float forwardZ = cos(radElevation) * cos(radAzimuth);

    // Calculate the right vector (world up is (0, 1, 0))
    float rightX = sin(radAzimuth - 3.14f / 2.0f);  // -cos(radAzimuth) = sin(radAzimuth - ¦Ð/2)
    float rightY = 0;
    float rightZ = cos(radAzimuth - 3.14f / 2.0f);
    // -¦Ð/2: turn 90 degrees to
    //          find the perpendicular direction to the forward direction vector

    /* In 3D space, given two vectors A = (Ax, Ay, Az) and B = (Bx, By, Bz), 
    the cross product C = A ¡Á B is defined as :
        Cx = Ay * Bz - Az * By
        Cy = Az * Bx - Ax * Bz
        Cz = Ax * By - Ay * Bx
    */

    // Up vector = Right vector x Forward vector
    float upX = forwardY * rightZ - forwardZ * rightY;
    float upY = forwardZ * rightX - forwardX * rightZ;
    float upZ = forwardX * rightY - forwardY * rightX;
    // to define the camera's orientation in the world

    // Speed to move per key press
    const float speed = 0.05f;

    // Adjust these values based on which keys are pressed
    float forwardDelta = 0.0f;
    float rightDelta = 0.0f;
    float upDelta = 0.0f;

    if (GetAsyncKeyState('W')) forwardDelta += speed;
    if (GetAsyncKeyState('S')) forwardDelta -= speed;
    if (GetAsyncKeyState('A')) rightDelta -= speed;
    if (GetAsyncKeyState('D')) rightDelta += speed;
    if (GetAsyncKeyState('Q')) upDelta -= speed;
    if (GetAsyncKeyState('E')) upDelta += speed;

    // Update camera position
    cameraPositionX += forwardDelta * forwardX + rightDelta * rightX + upDelta * upX;
    cameraPositionY += forwardDelta * forwardY + rightDelta * rightY + upDelta * upY;
    cameraPositionZ += forwardDelta * forwardZ + rightDelta * rightZ + upDelta * upZ;
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
    updateWASDQE();
    if (key == 27) exit(0);
    glutPostRedisplay();    
}

// Create Special Function (required for arrow keys)
void arrow_keys(int a_keys, int x, int y)
{
    switch (a_keys)
    {
    case GLUT_KEY_UP:
        cameraPositionY += 0.05;
        break;
    case GLUT_KEY_DOWN:
        cameraPositionY -= 0.05;
        break;
    case GLUT_KEY_LEFT:
        cameraPositionX -= 0.05;
        break;
    case GLUT_KEY_RIGHT:
        cameraPositionX += 0.05;
        break;
    }
}

// Create Main Function For Bringing It All Together
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    // Display Mode
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(500, 300);
    glutInitWindowSize(500, 500);
    // Window Title (argv[0] for current directory as title)
    glutCreateWindow("NeHe's OpenGL Framework");
    //glutFullScreen( );          // Put Into Full Screen
    // Go Into A 500 By 500 Window
    //glutReshapeWindow ( 500, 500 );
    InitGL();
    // Matching Earlier Functions To Their Counterparts
    glutDisplayFunc(display);
    glutReshapeFunc(ReSizeGLScene);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrow_keys);
    //glutIdleFunc(display);

    glutMotionFunc(handleMouseMove);

    // Initialize The Main Loop
    glutMainLoop();
}
