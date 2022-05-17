#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//FUNCOES
void configurarCamera(float aspecto) {
    //configurar para redimensionar
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //perspectiva
    gluPerspective(45.0, aspecto, 0.1, 100); //fovy, aspect, near, fear
    
    //configurar para redimensionar
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    //posicionamento
    gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0); //eyex, eyey, eyez, atx, aty, atz, upx, upx, y, upz
}

void configurarAmbiente() {
    //modo de display da janela
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

    //titulo da janela
    glutCreateWindow("Questao 01 - item a");

    //cor de fundo da janela
    glClearColor(0.0, 0.0, 0.0, 0.0); //rgba
}

void redimensionar(int largura_janela, int altura_janela) {
    //dados
    float aspecto = 0.0;

    //processamento
    if (altura_janela == 0)
        altura_janela = 1;
    
    aspecto = (float) largura_janela/altura_janela; //para a confirugacao
    glViewport(0, 0, largura_janela, altura_janela); //redimensiona

    configurarCamera(aspecto);
}

void desenharEixos3D() {
    glBegin(GL_LINES);
        //eixo x
        glColor3f(0.8, 0.0, 0.0);
        glVertex3f(-1.0, 0.0, 0.0); //xyz
        glColor3f(1.0, 0.0, 0.0); //rgb
        glVertex3f(1.0, 0.0, 0.0);
        //eixo y
        glColor3f(0.0, 0.8, 0.0);
        glVertex3f(0.0, -1.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, 1.0, 0.0);
        //eixo z
        glColor3f(0.0, 0.0, 0.8);
        glVertex3f(0.0, 0.0, -1.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, 1.0);
    glEnd();
}

void desenharPlano() {
    glBegin(GL_QUADS);
        glColor4f(0.3, 0.3, 0.3, 0.5); //rgba
        glVertex3f(-1.0, -1.0, 0.0);
        glVertex3f(-1.0, 1.0, 0.0);
        glVertex3f(1.0, 1.0, 0.0);
        glVertex3f(1.0, -1.0, 0.0);
    glEnd();
}

void renderizar() {
    //prepara a tela
    glEnable(GL_BLEND); //habilita transparencia
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //transparencia

    //desenha plano
    desenharPlano();

    //desenha os eixos 3d
    desenharEixos3D();

    //desenhar cone wireframe
    glColor3f(1.0, 1.0, 1.0);
    glutWireCone(0.15, 0.30, 20, 20);

    //"mostra o conteudo"
    glFlush();
}

//PROGRAMA PRINCIPAL
int main(int argc, char** argv) {
    //linux
    glutInit(&argc, argv);

    //configuracoes
    configurarAmbiente();
    configurarCamera(1.0);

    //define a funcao de renderizacao
    glutDisplayFunc(renderizar);

    //define a funcao para redimensionar
    glutReshapeFunc(redimensionar);

    //roda o programa
    glutMainLoop();

    return 0;
}