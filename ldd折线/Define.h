// MenuNo
#define �� 1001
#define ֱ�� 1002
#define ����� 1003
#define Բ 1004
#define ��Բ 1005
#define ��� 1006
#define ���� 1007
#define ������ 10031
#define �ı��� 10032
#define ����� 10033
#define ������ 10034
//#define ����� 10035
#define ��ɫ 2100
#define ��ɫ 2010
#define ��ɫ 2001
#define ��ɫ 2110
#define ��ɫ 2101
#define ��ɫ 2011
#define �Ŵ� 3001
#define ��С 3002
#define ���� 4001
#define ���� 4002
#define ���� 4003
#define ���� 4004
#define һ�� 5001
#define ���� 5002
#define ���� 5003
#define �ĺ� 5004
#define ��� 5005
#define ��ת 6
#define ����ɫ 7100
#define �����ɫ 7010
#define �����ɫ 7001
#define ����ɫ 7110
#define ����ɫ 7101
#define �����ɫ 7011
#define �� 8
#define ��� 9
#define ��ʼ 10
#define ���� 11
//Color Type
struct COLOR
{
	float R;
	float G;
	float B;
};
/*
//Graphics Type
enum Type
{
	notype = 0,
	point = 1,
	line = 2,
	polygon = 3,
	circle = 4,
	ellipse = 5
};*/
//rand
#define random(x) (rand()%x)
//DrawLine
#define drawOneLine(x1,y1,x2,y2) glBegin(GL_LINES);glVertex2f((x1),(y1));glVertex2f((x2),(y2));glEnd()
