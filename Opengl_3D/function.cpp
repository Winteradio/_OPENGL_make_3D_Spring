/*
* glViewport(int x, int y, int ����, int ����)
*	â ������ OpenGl�� �������� ����� ������ ������ �� �ִ�
*	x�� y�� ���۵Ǵ� ��ġ�̰� ���̿� ���̴� ���۵Ǵ� ��ġ���� ���̿� ���̸� �ǹ��Ѵ�
*
* [��� ��� �����ϴ� "��ĸ��"]
* glMatrixMode(GL_PROJETION)
*	glMatrixMode�� ������İ� ������� �ҷ����� �Լ��ν�
*	GL_PROJECTION / GL_MODELVIEW / GL_TEXTURE
*	!! OpenGL�� ����� ���ؼ� ���� ǥ���Ѵ�
*	GL_MODELVIEW( �� �� ��Ȳ ��� ) : �𵨺� ����� �ҷ��� �� ��Ŀ� ���� ���ؽ����� �������� �������� ���� ��ġ ����
*	GL_PROJECTION( ���� ��� ) : ������ ���� ��Ŀ� �������� ���������� ȭ�鿡 ���
*	GL_TEXTURE( �ؽ�ó ��� ) :
*	GL_COLOR( ���� ���) :
*	!! �𵨺� ����� ���� ��ġ�� ����ְ� ��������� �׷��� ������ �𵨵��� ���������� ���
* ------------------------------------------------------------
*
* [���� ��ȯ]
* gluLookAt(Eye[3], at[3], up[3])
*	ī�޶� ��Ÿ���� �Լ�
*	�����̶� 3���� ������ ����� �ٶ󺻴�
*	eye : ī�޶��� ������ ����(��ġ�� ��Ÿ����)
*	at : ī�޶��� ���� ����(ī�޶� �Ĵٺ��� ������ ��Ÿ����)
*	up : ī�޶��� ������ ����(ī�޶��� �������� ��Ÿ���� - ī�޶� ȸ�� X)
* ------------------------------------------------------------
*
* [�𵨸� ��ȯ]
* glTranslate[f,d](GLfloat x, GLfloat y, GLfloat z)
*	f : ���� ��κ� �̰��� ����Ѵ�
*	d :
*	x,y,z : ���� ��ǥ�� �������� �̵��Ѵ�.
*
* glRotate[f,d](GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
*	f :
*	d :
*	angle : ȸ���ϴ� ����
*	[x,y,z] : �� ���� ���͸� ������ angle�� �ݽð� �������� ȸ��
*
* glScalef(GLfloat x, GLfloat y, Glfloat z)
*	[x,y,z] : sx,sy,sz�踸ŭ �ǵ��� ũ�⸦ �����ϴ� �Լ��̴�
*
*
* [�� �� ��� ����]
* glLoadIdentity()
*	���� ����� �ʱ�ȭ(�������)��Ų��.
*	������İ� �𵨺� ��Ŀ� ���� ������ ���� �ʰ� ���� ����� ��Ŀ��� ������ ��ģ��.
* ------------------------------------------------------------
*
*
* [���� ����]
* gluPerspective(�þ߰�, ��Ⱦ��, �ո�, �޸�)
*	���� ������ ����� ����
*	��Ⱦ�� : ���̿� ������ ������ �ǹ��Ѵ�.
*	�ո� : �׸��� near�� �ǹ�
*	�޸� : �׸��� far�� �ǹ�
*	!! ���� ������ �Լ��δ� glFrustum
*
* glFrustum(left, right, bottom, top, zNear, zFar)
*
* ------------------------------------------------------------
*
*
* [���� ����]
* glortho(left, right, bottom, top, near, far)
*
* ------------------------------------------------------------
*
* [WGL]
* HDC >> hdc
* HGLRC >> hglrc
* 
* "�ĸ�����" : hdc / �Լ��� �����ϴ� ������ OpenGL ������ ���ý�Ʈ�� ���� ����̽� ���ý�Ʈ �ڵ�
* 
* "��ȯ ��" : �Լ��� �����ϸ�, ��ȿ�� OpenGL ������ ���ý�Ʈ�� �ڵ��� ��ȯ
*			�Լ��� �����ϸ�, NULL�� ��ȯ
*			Ȯ��� ���� ������ ��������, GetLastError�� ȣ��
* 
* "����" : ������ ���ý�Ʈ != ����̽� ���ý�Ʈ
*			������ ���ý�Ʈ�� �����ϱ� ���� ����̽� ���ý�Ʈ�� �ȼ� ������ ����
*			����̽� ���ý�Ʈ�� �ȼ� ���信 ���� �ڼ��� ������ "SetPixelFormat" �Լ� Ȯ��
* 
* wglCreateContext()
*	������ ���ý�Ʈ�� �����Ѵ�
*	hdc�� ����Ű�� ��ġ�� �׸��� �� ������ ���ο� OpenGL ������ ���ؽ�Ʈ�� �����Ѵ�
*	������ ���ý�Ʈ�� ����̽� ���ý�Ʈ�� ������ �ȼ� ������ ���´�
*
* wglDeleteContext()
*	������ ���ý�Ʈ�� �����Ѵ�
*
* wglMakeCurrent()
*	���� ������ ���ؽ�Ʈ�� �����Ѵ�.
*
* wglGetProcAddress()
*	Ȯ���Լ� �����͸� �����Ѵ�
*
* wglUseFontBitmap()
*	���� ���õ� GDI ��Ʈ�� ���� OpenGL ���÷��� ����Ʈ�� �����
*
* wglUseFontOutlines()
*	���� �ܰ��� �۲ð� ���� �Ϳ� ���÷��� ����Ʈ�� �����.
* ------------------------------------------------------------
*
* [GLUT]
* glutTimerFunc()
*	������ �ð� �Ŀ� ������ �Լ��� �ѹ� ȣ���Ѵ�.
*	�ٽ� ȣ���ҷ��� �Լ��� ��ȣ��
* ------------------------------------------------------------
*
* [�ȼ� ����]
* ChoosePixelFormat()
*	���� ������ �ȼ������� �����Ѵ�
*
* SetPixelFormat()
*	�ȼ������� ����̽� ���ؽ�Ʈ�� �����Ѵ�.
* ------------------------------------------------------------
*
* [ȭ�鼳��]
* ChangeDisplaySetting()
*	��üȭ������ �ٲ۴�
*
* SwapBuffer()
*	�ĸ���۸� ������۷� ��ü
*
* glClear()
*	ȭ��� ���۸� �����
*
* glClearColor()
*	ȭ���� ������ �����Ѵ�.
* ------------------------------------------------------------
*
* [�׸���]
* glBegin()
*	�⺻���� �׸��⸦ �����Ѵ�
*
* glEnd()
*	�⺻���� �׸��⸦ ��ģ��.
*
* glVertex()
*	������ �����Ѵ�
*
* glColor()
*	���� �����Ѵ�.
* ------------------------------------------------------------
*
* [���� �� ũ��]
* glPointSize()
*	���� ũ�⸦ �����Ѵ�
*
* glLineWidth()
*	���� ���⸦ �����Ѵ�
*
* glLineStipple()
*	���������� �����Ѵ�
* ------------------------------------------------------------
*
* [��Ÿ���� �׸���]
* glRectf()
*	�簢���� �׸���.
*
* auxSolidCube()
*	������ü�� �׸���
*
* auxSolidShpere()
*	���� �׸���
*
* auxSolidTorus()
*	��ȯ�� �׸���
* ------------------------------------------------------------
*
* [���¾˱�]
* glGetString()
*	OpenGL�� ����, Ȯ����� ����� �˾Ƴ���
*
* glGetBooleanv()
*	GLboolean Ÿ���� ���¸� �˾Ƴ���
*
* glGetDoublev()
*	GLdouble Ÿ���� ���¸� �˾Ƴ���
*
* glGetFloatv()
*	GLfloat Ÿ���� ���¸� �˾Ƴ���
*
* glGetIntegerv()
*	GLint Ÿ���� ���¸� �˾Ƴ���
*
* glIsEnable()
*	����� Ȱ��ȭ��Ų��
*
* glDisable()
*	����� ��Ȱ��ȭ��Ų��.
* ------------------------------------------------------------
*
* [���]
* glMatrixMode()
*	���� ����� �����Ѵ�
*
* glLoadIdentity()
*	������ ����� ������ķ� �����
*
* glLoadMatrix()
*	������ ����� �ֻ��� ��Ľ��ÿ� �ε��Ѵ�
*
* glMultiMatrix()
*	���� ��İ� ������ ����� ���Ѵ�
* ------------------------------------------------------------
*
* [����]
* glPushAttrib()
*	���� ������ �ӽ� �����Ѵ�
*
* glPopAttrib()
*	���� ������ �����Ѵ�
* ------------------------------------------------------------
*
* [������ȯ] - ī�޶� ����
* gluLookAt()
*	ī�޶��� ��ġ�� ������ �����Ѵ�
* ------------------------------------------------------------
*
* [�𵨸� ��ȯ]
* glRotate()
*	������ ���� �� ��ȯ
*
* glTranslate()
*	��ġ�� ���� �� ��ȯ
*
* glScale()
*	Ȯ�� �� ��� ��ȯ
* ------------------------------------------------------------
*
* [����]
* glOrtho()
*	������ ������ ��������
*
* gluOrth2D()
*	������ -1 ~ 1 �� ��������
*
* glFrustum()
*	���Ī ����ü ��������
*
* gluPerspective()
*	���� ����
*
* glViewport()
*	����Ʈ�� �����Ѵ�
* ------------------------------------------------------------
*
* [���̵�]
* glshadeModel()
*	���̵����� �����Ѵ�
* ------------------------------------------------------------
*
* [����]
* glMaterial()
*	ǥ�� ���� ����
*
* glLight()
*	���� ����
*
* glColorMaterial()
*	glColor�� ������ ���� ���� �Ӽ����� �����ǰ� �Ѵ�
*
* glLightModel()
*	���� ���� �����Ѵ�
*
* glNormal3()
*	����ȭ�� �������͸� �����Ѵ�
* ------------------------------------------------------------
*
* [ȥ��]
* glBlendFunc()
*	������ ����� ȥ���� ����
* ------------------------------------------------------------
*
* [����]
* glDepthMask()
*	���� ���۸��(�б�����, ����)�� �����Ѵ�
* ------------------------------------------------------------
*
* [��Ʈ��]
* glRasterPos()
*	��Ʈ���̳� �̹����� �׷��� ��ġ�� �����Ѵ�. �����ϴܺ��� �׸���
*
* glBitmap()
*	��Ʈ���� �׸���
*
* glDrawPixels()
*	�ȼ����� �׸���
*
* glReadPixels()
*	�ȼ��� �о�´�
*
* glCopyPixes()
*	ȭ�鵥���͸� �����Ѵ�
*
* glPixelZoom()
*	�̹����� Ȯ��, ��� �� �����´�
*
* glPixelStorei()
*	�ȼ� �������� �����Ѵ�
*
* auxDIBImageLoad()
*	DIB �̹������ε��Ѵ�
*
* AUX_RGBImageRec
*	auxDIBImageLoad�� �ε�� �̹��� �����͸� �����ϴ� ����ü
* ------------------------------------------------------------
*
* [�ؽ���]
* glGenTexture()
*	�ؽ��� �̸��� �����Ѵ�
*
* glBindTexture()
*	�ؽ��� �̸��� �ؽ��� �����Ϳ� �����Ѵ�
*
* glTexParameter()
*	�ؽ����� ���͸� ����� �����Ѵ�
*
* glTexEnvi()
*	�ؽ��İ� ������ �� �ؽ����� ����� ���� �ȼ�������� ���踦 �����Ѵ�
*
* glTexImage2D()
*	2D �̹����� �ؽ��ķ� �޸𸮿� �ε��Ѵ�
*
* glTexImage1D()
*	1D �̹����� �ؽ��ķ� �޸𸮿� �ε��Ѵ�
*
* glTexCoord2()
*	�ؽ��� ��ǥ�� �����Ѵ�
*
* gluBuild2DMipmaps()
*	�Ӹ��� �ڵ������Ѵ�
*
* glTexGen()
*	�ؽ��� ��ǥ�� �ڵ����� �����Ѵ�
*
*
* [����]
* glMatrixMode(GL_MODELVIEW)
* glLoadIdentity()
* glGetFloatv(GL_MODELVIEW_MATRIX,matrix)
*	�𵨺� ����� �ҷ��´� (glMatrixMode(GL_MODELVIEW))
*	���� ����� �ʱ�ȭ (glLoadIdentity())
*	���� ��İ��� matrix�� ���� (glGetFloatv(GL_MODELVIEW_MATRIX,matrix)
* ------------------------------------------------------------
*
*/