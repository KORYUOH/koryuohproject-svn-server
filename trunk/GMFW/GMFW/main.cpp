//*	DirectX (Vista以降でないと起動しない)
#include	<Render/DirectX/DirectX10.h>
//初期化
HRESULT CALLBACK OnD3D10CreateDevice( ID3D10Device* device, const DXGI_SURFACE_DESC *surfaceDesc, void* userContext){
	return S_OK;
}
//描画
void CALLBACK OnD3D10FrameRender( ID3D10Device* device,double time, float elapsedTime, void* userContext){

}
void CALLBACK On3D10DestoroyDevice(void* pUserContext){
}

//*/

//*	OpenGL
#include	<Render/OpenGL/OpenGL.h>
//初期化
void init(){
}

//描画
void display(){
	//画面消去
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//強制描画
	glFlush();
	//ダブルバッファ切り替え
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
	//ウィンドウセッティング
	glutInit( &argc, argv);
	glutInitDisplayMode( GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Sample");
	//初期化
	init();
	//表示関数設定
	glutDisplayFunc(display);
	//メインループ
	glutMainLoop();
	//*/
	return 0;
}