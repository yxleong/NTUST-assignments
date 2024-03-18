#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	shader_example::MyForm windowsForm;
	Application::Run(%windowsForm);
}