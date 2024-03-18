#pragma once
#include "DotNetUtilities.h"
#include "object.h"
glm::mat4 ProjectionMatrix;
glm::mat4 ViewMatrix; 
#include <cmath> // For sin() and cos()
#define M_PI 3.14159265358979323846

//For OpenGL
double deltaMove = 0;
double x = 0.0f, z = 15, y = 0;
double lx = 0.0f, lz = -1.0f, ly = 0.0f;
double angleH = 90;
double angleV = 90;
double newCameraPosition[3] = { 0,40,40 };
double cameraDistance = 40;
double translateDelta[3];
double targetPosition[3] = { 0,0,0 };
double ZoomValue = 0.08;
double prelx = 0.0f;
double prely = 0.0f;
bool isRotate = false;
bool isTranslate = false;
int xOrigin = -1;
int yOrigin = -1;
double maxAngleV = 180;
double minAngleV = 0;
double minDistance = 0.1;

bool reTime = false;
float countTime = 0;
object grid;
object pentagram;

namespace shader_example {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: HKOGLPanel::HKOGLPanelControl^  hkoglPanelControl1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			HKOGLPanel::HKCOGLPanelCameraSetting^  hkcoglPanelCameraSetting1 = (gcnew HKOGLPanel::HKCOGLPanelCameraSetting());
			HKOGLPanel::HKCOGLPanelPixelFormat^  hkcoglPanelPixelFormat1 = (gcnew HKOGLPanel::HKCOGLPanelPixelFormat());
			this->hkoglPanelControl1 = (gcnew HKOGLPanel::HKOGLPanelControl());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// hkoglPanelControl1
			// 
			hkcoglPanelCameraSetting1->Far = 1000;
			hkcoglPanelCameraSetting1->Fov = 45;
			hkcoglPanelCameraSetting1->Near = -1000;
			hkcoglPanelCameraSetting1->Type = HKOGLPanel::HKCOGLPanelCameraSetting::CAMERATYPE::ORTHOGRAPHIC;
			this->hkoglPanelControl1->Camera_Setting = hkcoglPanelCameraSetting1;
			this->hkoglPanelControl1->Location = System::Drawing::Point(12, 12);
			this->hkoglPanelControl1->Name = L"hkoglPanelControl1";
			hkcoglPanelPixelFormat1->Accumu_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			hkcoglPanelPixelFormat1->Alpha_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			hkcoglPanelPixelFormat1->Stencil_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			this->hkoglPanelControl1->Pixel_Format = hkcoglPanelPixelFormat1;
			this->hkoglPanelControl1->Size = System::Drawing::Size(567, 428);
			this->hkoglPanelControl1->TabIndex = 0;
			this->hkoglPanelControl1->Load += gcnew System::EventHandler(this, &MyForm::hkoglPanelControl1_Load);
			this->hkoglPanelControl1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::hkoglPanelControl1_Paint);
			this->hkoglPanelControl1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseDown);
			this->hkoglPanelControl1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseMove);
			this->hkoglPanelControl1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseUp);
			this->hkoglPanelControl1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseWheel);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 452);
			this->Controls->Add(this->hkoglPanelControl1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		void UpdateViewMatrix()
		{
			double theta = angleV * (3.14159f / 180.0f);
			double phi = angleH * (3.14159f / 180.0f);

			newCameraPosition[0] = cameraDistance * sin(theta) * cos(phi);
			newCameraPosition[1] = cameraDistance * cos(theta);
			newCameraPosition[2] = cameraDistance * sin(theta) * sin(phi);

			for (int i = 0; i < 3; i++)
				targetPosition[i] += translateDelta[i];
			for (int i = 0; i < 3; i++)
				newCameraPosition[i] += targetPosition[i];

			ViewMatrix = glm::lookAt(
				glm::vec3(newCameraPosition[0], newCameraPosition[1], newCameraPosition[2]), // Camera in World Space
				glm::vec3(targetPosition[0], targetPosition[1], targetPosition[2]), // and looks at the origin
				glm::vec3(0, 1, 0)  // Head is up (set to 0,1,0 to look upside-down)
			);
		}
		void setGrid()
		{
			// Set up Grid
			const int hw = 5000;
			const int step = 50;
			glm::vec3 gridColor = glm::vec3(0.2, 0.2, 0.2);
			for (int i = -hw; i <= hw; i += step)
			{

				grid.setPoint(glm::vec3(i, 0, -hw));
				grid.setPoint(glm::vec3(i, 0, hw));
				grid.setPoint(glm::vec3(-hw, 0, i));
				grid.setPoint(glm::vec3(hw, 0, i));

				grid.setColor(gridColor);
				grid.setColor(gridColor);
				grid.setColor(gridColor);
				grid.setColor(gridColor);
			}
			grid.setPoint(glm::vec3(0, 0, 0));
			grid.setPoint(glm::vec3(0, 1000, 0));
			grid.setColor(glm::vec3(0.4, 0.4, 0.4));
			grid.setColor(glm::vec3(0.4, 0.4, 0.4));
		}
		/*void setBox(float size)
		{
			for (int i = 0; i < 24; i++)
			{
				double v1 = rand() % 100;
				double v2 = rand() % 100;
				double v3 = rand() % 100;
				v1 = v1 / 100;
				v2 = v2 / 100;
				v3 = v3 / 100;
				box.setColor(glm::vec3(v1, v2, v3));
			}

			box.setPoint(glm::vec3(-size, size, size));
			box.setPoint(glm::vec3(-size, -size, size));
			box.setPoint(glm::vec3(size, -size, size));
			box.setPoint(glm::vec3(size, size, size));

			box.setPoint(glm::vec3(-size, size, -size));
			box.setPoint(glm::vec3(-size, -size, -size));
			box.setPoint(glm::vec3(-size, -size, size));
			box.setPoint(glm::vec3(-size, size, size));

			box.setPoint(glm::vec3(size, size, size));
			box.setPoint(glm::vec3(size, -size, size));
			box.setPoint(glm::vec3(size, -size, -size));
			box.setPoint(glm::vec3(size, size, -size));

			box.setPoint(glm::vec3(size, size, -size));
			box.setPoint(glm::vec3(size, -size, -size));
			box.setPoint(glm::vec3(-size, -size, -size));
			box.setPoint(glm::vec3(-size, size, -size));

			box.setPoint(glm::vec3(-size, size, -size));
			box.setPoint(glm::vec3(-size, size, size));
			box.setPoint(glm::vec3(size, size, size));
			box.setPoint(glm::vec3(size, size, -size));

			box.setPoint(glm::vec3(size, -size, size));
			box.setPoint(glm::vec3(-size, -size, size));
			box.setPoint(glm::vec3(-size, -size, -size));
			box.setPoint(glm::vec3(size, -size, -size));
		}*/

		void setPentagram(float size) {
			float pentagramOuterRadius = size;
			int pentagramArmsCount = 5;
			const float angleBetweenArms = 2.0f * M_PI / pentagramArmsCount;
			const int baseCircleResolution = 400;	// approximate the number of points along the perimeter of the circular base of each cone 
			glm::vec3 pentagramCenter(0.0f, 0.0f, 0.0f);

			for (int armIndex = 1; armIndex <= pentagramArmsCount; armIndex++) {
				float armAngle = armIndex * angleBetweenArms;
				glm::vec3 armTipPosition(cos(armAngle) * pentagramOuterRadius, sin(armAngle) * pentagramOuterRadius, 0.0f);
				glm::vec3 coneBaseCenter = armTipPosition * 0.2f;	// length

				std::vector<glm::vec3> coneBasePoints;
				for (int pointIndex = 0; pointIndex < baseCircleResolution; ++pointIndex) {
					float basePointAngle = 2.0f * M_PI * pointIndex / baseCircleResolution;
					glm::vec3 basePoint = coneBaseCenter + (pentagramOuterRadius / 4.0f) * glm::vec3(cos(basePointAngle), sin(basePointAngle), 0);
					coneBasePoints.push_back(basePoint);
				}
				for (int pointIndex = 0; pointIndex < baseCircleResolution; pointIndex++) {

					double redComponent = rand() % 100 / 100.0;
					double greenComponent = rand() % 100 / 100.0;
					double blueComponent = rand() % 100 / 100.0;
					glm::vec3 coneColor(redComponent, greenComponent, blueComponent);

					pentagram.setPoint(coneBasePoints[pointIndex]);
					pentagram.setColor(coneColor);

					pentagram.setPoint(coneBasePoints[(pointIndex + 1) % baseCircleResolution]);
					pentagram.setColor(coneColor);

					pentagram.setPoint(armTipPosition);
					pentagram.setColor(coneColor);
				}
			}
		}
	private: System::Void hkoglPanelControl1_Load(System::Object^  sender, System::EventArgs^  e) {

		//glew初始
		GLenum res = glewInit();
		if (res != GLEW_OK) {
			fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		}
		glClearColor(0, 0, 0, 1);

		//Set up MVP matrix
		ProjectionMatrix = glm::perspective(60.0f, 588.0f / 470.0f, 0.1f, 2000.0f);
		ViewMatrix = glm::lookAt(
			glm::vec3(newCameraPosition[0], newCameraPosition[1], newCameraPosition[2]), // Camera in World Space
			glm::vec3(targetPosition[0], targetPosition[1], targetPosition[2]), // and looks at the origin
			glm::vec3(0, 1, 0)  // Head is up (set to 0,1,0 to look upside-down)
		);
		//物件初始
		grid.initialize();
		grid.setShader("./Shader/Base.vert", "./Shader/Base.frag");
		setGrid();


		pentagram.initialize();
		pentagram.setShader("./Shader/Base.vert", "./Shader/Base.frag");
		setPentagram(10);

	}
	void boxUpdate()
	{
		mat4 model_matrix[2];
		mat4 scale_matrix, translation_matrix, rotation_matrix;
		scale_matrix = pentagram.setScale(2.0f, 2.0f, 2.0f);

		translation_matrix = pentagram.setTranslate(countTime, 0.0f, 0.0f);
		model_matrix[0] = translation_matrix*scale_matrix;  //相對於原點的動作及位置

		pentagram.render(GL_QUADS, ProjectionMatrix, ViewMatrix, model_matrix[0]);

		rotation_matrix = pentagram.setRotate(countTime * 2, 0.0f, 1.0f, 0);
		translation_matrix = pentagram.setTranslate(0,20,0);

		model_matrix[1] = model_matrix[0] * translation_matrix * rotation_matrix; //相對於model 0 的動作及位置
		
		pentagram.render(GL_QUADS, ProjectionMatrix, ViewMatrix, model_matrix[1]);
	}
	private: System::Void hkoglPanelControl1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		UpdateViewMatrix();

		//---------------------------------
		mat4 identifyMatrix = glm::mat4(0);
		identifyMatrix[0][0] = 1.0;
		identifyMatrix[1][1] = 1.0;
		identifyMatrix[2][2] = 1.0;
		identifyMatrix[3][3] = 1.0;
		//---------------------------------
		boxUpdate();


		grid.render(GL_LINES, ProjectionMatrix, ViewMatrix, identifyMatrix);
	}

	private: System::Void hkoglPanelControl1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{

		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isRotate = true;
			xOrigin = e->X;
			yOrigin = e->Y;
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Middle)
		{
			isTranslate = true;
			xOrigin = e->X;
			yOrigin = e->Y;
		}
	}
	private: System::Void hkoglPanelControl1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			isRotate = false;
			prelx = lx;
			prely = ly;
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Middle)
		{
			isTranslate = false;
			translateDelta[0] = 0;
			translateDelta[1] = 0;
			translateDelta[2] = 0;
		}
	}
	private: System::Void hkoglPanelControl1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (isRotate)
		{
			angleV -= (e->Y - yOrigin) / 10.0f;
			angleH += (e->X - xOrigin) / 10.0f;
			angleV = (((angleV) > (minAngleV)) ? (angleV) : (minAngleV));
			angleV = (((angleV) < (maxAngleV)) ? (angleV) : (maxAngleV));
			xOrigin = e->X;
			yOrigin = e->Y;
		}
		if (isTranslate)
		{
			double phi = angleH * (3.14159f / 180.0f);
			translateDelta[0] = (e->X - xOrigin) / 10.0f;
			translateDelta[1] = (e->Y - yOrigin) / 10.0f;
			translateDelta[2] = 0.0f;

			translateDelta[2] = translateDelta[0] * cos(phi);
			translateDelta[0] = -1.0*translateDelta[0] * sin(phi);
			xOrigin = e->X;
			yOrigin = e->Y;
		}
	}
	private: System::Void hkoglPanelControl1_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (e->Delta > 0)
		{
			cameraDistance -= 0.05f * abs(cameraDistance);
			cameraDistance = (((cameraDistance) > (minDistance)) ? (cameraDistance) : (minDistance));
		}
		else
		{
			cameraDistance += 0.05f * abs(cameraDistance);
			cameraDistance = (((cameraDistance) > (minDistance)) ? (cameraDistance) : (minDistance));
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (countTime > 80.0f)
			reTime =true;
		if (countTime < -80.0f)
			reTime = false;
		if (reTime)
			countTime -= 1.0f;
		else
			countTime += 1.0f;
		hkoglPanelControl1->Invalidate();
	}
	};
}
