#include <GL/glut.h>
#include <iostream>
using namespace std;
#include "MainCtrl.h"
MainCtrl MC;
bool loopr = false;
void Init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-800 / 2, 800 / 2, -600 / 2, 600 / 2, -800 / 2, 800 / 2);
	glClear(GL_COLOR_BUFFER_BIT);
	//��ʼ������
	glColor3f(0.0f, 0.0f, 0.0f);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0101);
	drawOneLine(-400, 200, 400, 200);
	drawOneLine(-400, 100, 400, 100);
	drawOneLine(-400, 0, 400, 0);
	drawOneLine(-400, -100, 400, -100);
	drawOneLine(-400, -200, 400, -200);
	drawOneLine(-300, -300, -300, 300);
	drawOneLine(-200, -300, -200, 300);
	drawOneLine(-100, -300, -100, 300);
	drawOneLine(0, -300, 0, 300);
	drawOneLine(100, -300, 100, 300);
	drawOneLine(200, -300, 200, 300);
	drawOneLine(300, -300, 300, 300);
	glDisable(GL_LINE_STIPPLE);
	glFlush();
}
void myDisplay()
{
	/*Point P(200,200);
	//P.setLineColor(1,0,0);
	P.setLineWidth(5);
	P.Draw();*/
	/*Line L(0,0,100,-100);
	//L.setLineColor(1, 0, 0);
	L.setLineWidth(5);
	L.Draw();*/
	/*
	COORD b = {0,0};
	COORD b2 = {100,0};
	COORD e = {200,50};
	COORD e2 = {100,50};
	COORD e3 = {-200,200};
	COORD c[] = {b,b2,e,e2,e3};
	class::Polygon P(5,c);
	P.setLineColor(1, 0, 1);
	P.setLineWidth(5);
	P.Draw();*/
	/*COORD center = {0.0, 0.0};
	Circle C(center, 100);
	C.setLineColor(1,0,0);
	C.setLineWidth(5);
	C.Draw();
	COORD c = {50,100};
	Elipse E(c, 100,40);
	E.setLineWidth(5);
	E.Draw();*/
	//MainCtrl MC;
	//MC.DrawGraph();
}
void processMenuEvents(int option)
{
	switch (option)
	{
	case ��ʼ:
		MC.DrawGraph();
		break;
	case ��:
	{
		//int pointX = -400 + random(200) ;
		//int pointY = 100 + random(200);
		float pointX;
		float pointY;
		cout << "#CGP# �����������꣬�ÿո������-400<X<400, -300<Y<300��: ";
		cin >> pointX >> pointY;
		Graphics* point = new Point(pointX, pointY);
		point->setLineWidth(2);
		point->setLineColor(1, 0, 0);
		point->graphicsType = "point";
		MC.GraphList.push_back(point);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case ֱ��:
	{
		/*int lineSX = -200 + random(200);
		int lineSY = 100 + random(200);
		int lineEX = -200 + random(200);
		int lineEY = 100 + random(200);*/
		int lineSX, lineSY, lineEX, lineEY;
		cout << "#CGP# ������ֱ�������յ�����꣬�ո������-400<X<400, -300<Y<300��: ";
		cin >> lineSX >> lineSY >> lineEX >> lineEY;
		Graphics* line = new Line(lineSX, lineSY, lineEX, lineEY);
		line->setLineWidth(2);
		line->setLineColor(0, 1, 0);
		line->graphicsType = "line";
		MC.GraphList.push_back(line);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case ������:
	{
		int n = 3;
		/*COORD c31 = { random(400), 100+random(200)};
		COORD c32 = { random(400), 100+random(200)};
		COORD c33 = { random(400), 100+random(200)};
		COORD C[] = { c31,c32,c33};*/
		COORD C[3];
		cout << "#CGP# �����������θ�������꣬�ո������-400<X<400, -300<Y<300��: ";
		cin >> C[0].X >> C[0].Y >> C[1].X >> C[1].Y >> C[2].X >> C[2].Y;
		Graphics* polygon = new class::Polygon(n, C);
		polygon->setLineWidth(2);
		polygon->setLineColor(0, 0, 1);
		polygon->graphicsType = "polygon";
		MC.GraphList.push_back(polygon);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case �ı���:
	{
		int n = 4;
		/*COORD c41 = { random(400), 100+random(200)};
		COORD c42 = { random(400), 100+random(200)};
		COORD c43 = { random(400), 100+random(200)};
		COORD c44 = { random(400), 100+random(200)};
		COORD C[] = { c41,c42,c43,c44};*/
		COORD C[4];
		cout << "#CGP# �������ı��θ�������꣬�ÿո������-400<X<400, -300<Y<300��: ";
		cin >> C[0].X >> C[0].Y >> C[1].X >> C[1].Y >> C[2].X >> C[2].Y >> C[3].X >> C[3].Y;
		Graphics* polygon = new class::Polygon(n, C);
		polygon->setLineWidth(2);
		polygon->setLineColor(0, 1, 1);
		polygon->graphicsType = "polygon";
		MC.GraphList.push_back(polygon);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case �����:
	{
		int n = 5;
		/*COORD c51 = { random(400), -300+random(200)};
		COORD c52 = { random(400), -300+random(200)};
		COORD c53 = { random(400), -300+random(200)};
		COORD c54 = { random(400), -300+random(200)};
		COORD c55 = { random(400), -300+random(200)};
		COORD C[] = { c51,c52,c53,c54, c55};*/
		COORD C[5];
		cout << "#CGP# ����������θ�������꣬�ÿո������-400<X<400, -300<Y<300��: ";
		cin >> C[0].X >> C[0].Y >> C[1].X >> C[1].Y >> C[2].X >> C[2].Y >> C[3].X >> C[3].Y >> C[4].X >> C[4].Y;
		Graphics* polygon = new class::Polygon(n, C);
		polygon->setLineWidth(2);
		polygon->setLineColor(1, 0, 1);
		polygon->graphicsType = "polygon";
		MC.GraphList.push_back(polygon);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case ������:
	{
		int n = 6;
		/*COORD c61 = { random(400), -300+random(200)};
		COORD c62 = { random(400), -300+random(200)};
		COORD c63 = { random(400), -300+random(200)};
		COORD c64 = { random(400), -300+random(200)};
		COORD c65 = { random(400), -300+random(200)};
		COORD c66 = { random(400), -300+random(200)};
		COORD C[] = { c61,c62,c63,c64, c65,c66};*/
		COORD C[6];
		cout << "#CGP# �����������θ�������꣬�ÿո������-400<X<400, -300<Y<300��: ";
		cin >> C[0].X >> C[0].Y >> C[1].X >> C[1].Y >> C[2].X >> C[2].Y >> C[3].X >> C[3].Y >> C[4].X >> C[4].Y >> C[5].X >> C[5].Y;
		Graphics* polygon = new class::Polygon(n, C);
		polygon->setLineWidth(2);
		polygon->setLineColor(1, 1, 0);
		polygon->graphicsType = "polygon";
		MC.GraphList.push_back(polygon);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case Բ:
	{
		//COORD circleCenter = { random(200), -100+random(200) };
		COORD circleCenter;
		int radius;
		cout << "#CGP# ������Բ��Բ������Ͱ뾶���ո������-400<X<400, -300<Y<300��: ";
		cin >> circleCenter.X >> circleCenter.Y >> radius;
		Graphics* circle = new Circle(circleCenter, radius);
		circle->setLineWidth(2);
		circle->setLineColor(0.5, 0.5, 1);
		circle->graphicsType = "circle";
		MC.GraphList.push_back(circle);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case ��Բ:
	{
		//COORD elipseCenter = { -200+random(200), -100+random(200) };
		COORD elipseCenter;
		int a, b;
		cout << "#CGP# ������Բ��Բ������ͳ����ᣬ�ո������-400<X<400, -300<Y<300��: ";
		cin >> elipseCenter.X >> elipseCenter.Y >> a >> b;
		Graphics* elipse = new Elipse(elipseCenter, a, b);
		elipse->setLineWidth(2);
		elipse->setLineColor(0.3, 0.6, 0.9);
		elipse->graphicsType = "ellipse";
		MC.GraphList.push_back(elipse);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case ���:
	{
		double size, x, y, z;
		cout << "#CGP# ���������Ĺ���С��λ�����꣺ ";
		cin >> size >> x >> y >> z;
		Graphics* teapot = new Teapot(size, x, y, z);
		teapot->setLineWidth(2);
		teapot->setLineColor(0.6, 0.3, 0.4);
		teapot->graphicsType = "teapot";
		MC.GraphList.push_back(teapot);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case ����:
	{
		COORD c[4];
		cout << "#CGP# ���������ߵ��ĸ������꣬�ո������-400<X<400, -300<Y<300����";
		cin >> c[0].X >> c[0].Y >> c[1].X >> c[1].Y >> c[2].X >> c[2].Y >> c[3].X >> c[3].Y;
		Graphics* curve = new Curve(4, c);
		curve->setLineWidth(2);
		curve->graphicsType == "curve";
		MC.GraphList.push_back(curve);
		MC.GraphList[MC.GraphList.size() - 1]->Draw();
		break;
	}
	case ��ɫ:
		MC.SetLineColor(1, 0, 0);
		break;
	case ��ɫ:
		MC.SetLineColor(0, 1, 0);
		break;
	case ��ɫ:
		MC.SetLineColor(0, 0, 1);
		break;
	case ��ɫ:
		MC.SetLineColor(1, 1, 0);
		break;
	case ��ɫ:
		MC.SetLineColor(1, 0, 1);
		break;
	case ��ɫ:
		MC.SetLineColor(0, 1, 1);
		break;
	case �Ŵ�:
		MC.Increase();
		break;
	case ��С:
		MC.Decrease();
		break;
	case ����:
		MC.UpGraph();
		break;
	case ����:
		MC.DownGraph();
		break;
	case ����:
		MC.LeftGraph();
		break;
	case ����:
		MC.RightGraph();
		break;
	case һ��:
		MC.SetLineWidth(2);
		break;
	case ����:
		MC.SetLineWidth(5);
		break;
	case ����:
		MC.SetLineWidth(8);
		break;
	case �ĺ�:
		MC.SetLineWidth(10);
		break;
	case ���:
		MC.SetLineWidth(15);
		break;
	case ��:
	{
		string fn;
		cout << "#CGP# �����������ļ���·��: ";
		cin >> fn;
		MC.ReadFromFile(fn);
		MC.DrawGraph();
		break;
	}
	case ��ת:
		MC.Rotate(' ');
		break;
	case ���:
		MC.Disappear();
		break;
	case ����:
	{
		string fn;
		cout << "�����뱣����ļ�·��: ";
		cin >> fn;
		MC.SaveToFile(fn);
		break;
	}
	case ����ɫ:
		MC.Fill(1, 0, 0);
		break;
	case �����ɫ:
		MC.Fill(0, 1, 0);
		break;
	case �����ɫ:
		MC.Fill(0, 0, 1);
		break;
	case ����ɫ:
		MC.Fill(1, 1, 0);
		break;
	case ����ɫ:
		MC.Fill(1, 0, 1);
		break;
	case �����ɫ:
		MC.Fill(0, 1, 1);
		break;
	default:
		break;
	}
}
void createGlutMenu()
{
	int subMenu11;
	subMenu11 = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("������", ������);
	glutAddMenuEntry("�ı���", �ı���);
	glutAddMenuEntry("�����", �����);
	glutAddMenuEntry("������", ������);
	int subMenu1;
	subMenu1 = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("��", ��);
	glutAddMenuEntry("ֱ��", ֱ��);
	glutAddSubMenu("�����", subMenu11);
	glutAddMenuEntry("Բ", Բ);
	glutAddMenuEntry("��Բ", ��Բ);
	glutAddMenuEntry("����ͼ", ���);
	glutAddMenuEntry("����", ����);
	int subMenu2;
	subMenu2 = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("��ɫ", ��ɫ);
	glutAddMenuEntry("��ɫ", ��ɫ);
	glutAddMenuEntry("��ɫ", ��ɫ);
	glutAddMenuEntry("��ɫ", ��ɫ);
	glutAddMenuEntry("��ɫ", ��ɫ);
	glutAddMenuEntry("��ɫ", ��ɫ);
	int subMenu3;
	subMenu3 = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("�Ŵ�", �Ŵ�);
	glutAddMenuEntry("��С", ��С);
	int subMenu4;
	subMenu4 = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("����", ����);
	glutAddMenuEntry("����", ����);
	glutAddMenuEntry("����", ����);
	glutAddMenuEntry("����", ����);
	int subMenu5;
	subMenu5 = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("һ��", һ��);
	glutAddMenuEntry("����", ����);
	glutAddMenuEntry("����", ����);
	glutAddMenuEntry("�ĺ�", �ĺ�);
	glutAddMenuEntry("���", ���);
	int subMenu6;
	subMenu6 = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("��ɫ", ����ɫ);
	glutAddMenuEntry("��ɫ", �����ɫ);
	glutAddMenuEntry("��ɫ", �����ɫ);
	glutAddMenuEntry("��ɫ", ����ɫ);
	glutAddMenuEntry("��ɫ", ����ɫ);
	glutAddMenuEntry("��ɫ", �����ɫ);
	int menu;
	menu = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("��ʼ", ��ʼ);
	glutAddSubMenu("�½�", subMenu1);
	glutAddMenuEntry("��", ��);
	glutAddSubMenu("��ɫ", subMenu2);
	glutAddSubMenu("�߿�", subMenu5);
	glutAddSubMenu("ƽ��", subMenu4);
	glutAddSubMenu("����", subMenu3);
	glutAddMenuEntry("��ת", ��ת);
	glutAddSubMenu("���", subMenu6);
	glutAddMenuEntry("���", ���);
	glutAddMenuEntry("����", ����);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			//ϵͳ����ϵ���������ϵ��ת��
			MC.c[0].X = x - 400;
			MC.c[0].Y = -(y - 300);
		}
		else if (state == GLUT_UP)
		{
			MC.c[1].X = x - 400;
			MC.c[1].Y = -(y - 300);
			MC.CutGraph();
		}
		cout << x - 400 << ',' << -(y - 300) << endl;
	}
}
void timer(int p)
{
	for (auto i = MC.GraphList.begin(); i != MC.GraphList.end(); i++)
	{
		if ((*i)->graphicsType == "teapot")
		{
			(*i)->Disappear();
			(*i)->rotateX -= 5;
			(*i)->Draw();
		}
	}
	//glutPostRedisplay();       //marks the current window as needing to be redisplayed.
	if (loopr)
		glutTimerFunc(200, timer, 0);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	{
		for (auto i = MC.GraphList.begin(); i != MC.GraphList.end(); i++)
		{
			if ((*i)->graphicsType == "teapot")
			{
				(*i)->Disappear();
				(*i)->Rotate('w');
				(*i)->Draw();
			}
		}
		break;
	}
	case 'a':
	{
		for (auto i = MC.GraphList.begin(); i != MC.GraphList.end(); i++)
		{
			if ((*i)->graphicsType == "teapot")
			{
				(*i)->Disappear();
				(*i)->Rotate('a');
				(*i)->Draw();
			}
		}
		break;
	}
	case 's':
	{
		for (auto i = MC.GraphList.begin(); i != MC.GraphList.end(); i++)
		{
			if ((*i)->graphicsType == "teapot")
			{
				(*i)->Disappear();
				(*i)->Rotate('s');
				(*i)->Draw();
			}
		}
		break;
	}
	case 'd':
	{
		for (auto i = MC.GraphList.begin(); i != MC.GraphList.end(); i++)
		{
			if ((*i)->graphicsType == "teapot")
			{
				(*i)->Disappear();
				(*i)->Rotate('d');
				(*i)->Draw();
			}
		}
		break;
	}
	case 'e':
		loopr = false;
		break;
	case 'r':
		loopr = true;
		glutTimerFunc(200, timer, 0);
		break;
	default:
		break;
	}
}
void keyboardSpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		MC.LeftGraph();
		break;
	case GLUT_KEY_UP:
		MC.UpGraph();
		break;
	case GLUT_KEY_RIGHT:
		MC.RightGraph();
		break;
	case GLUT_KEY_DOWN:
		MC.DownGraph();
		break;

	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(800, 600);
	glutCreateWindow("CG Program");

	Init();
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);
	createGlutMenu();
	glutMainLoop();
	return 0;
}
