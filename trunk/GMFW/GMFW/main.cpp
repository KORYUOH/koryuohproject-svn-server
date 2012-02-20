//*	DirectX (Vista�ȍ~�łȂ��ƋN�����Ȃ�)
#include	<Render/DirectX/DirectX10.h>
//������
HRESULT CALLBACK OnD3D10CreateDevice( ID3D10Device* device, const DXGI_SURFACE_DESC *surfaceDesc, void* userContext){
	return S_OK;
}
//�`��
void CALLBACK OnD3D10FrameRender( ID3D10Device* device,double time, float elapsedTime, void* userContext){

}
void CALLBACK On3D10DestoroyDevice(void* pUserContext){
}

//*/

//*	OpenGL
#include	<Render/OpenGL/OpenGL.h>
//������
void init(){
}

//�`��
void display(){
	//��ʏ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//�����`��
	glFlush();
	//�_�u���o�b�t�@�؂�ւ�
	glutSwapBuffers();

}


//*/
int main(int argc,char **argv){
	//*	DirectX
	DXUTSetCallbackD3D10DeviceCreated(OnD3D10CreateDevice);
	DXUTSetCallbackD3D10DeviceDestroyed(On3D10DestoroyDevice);
	DXUTSetCallbackD3D10FrameRender(OnD3D10FrameRender);
	DXUTInit( true ,true , NULL);
	DXUTCreateWindow(L"Sample");
	DXUTCreateDevice(true,500,500);
	DXUTMainLoop();
	return DXUTGetExitCode();
	//*/

	/*	OpenGL
	//�E�B���h�E�Z�b�e�B���O
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Sample");
	//������
	init();
	//�\���֐��ݒ�
	glutDisplayFunc(display);
	//���C�����[�v
	glutMainLoop();
	//*/
	return 0;
}