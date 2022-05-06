#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

float grausParaRadianos(float angulo_graus) {
    return (angulo_graus * 2 * M_PI)/360.0;
}

void desenharCirculo(float raio, float x0, float y0, int definicao, float vermelho, float verde, float azul) {
    int i;
    float passo = grausParaRadianos(360.0/definicao);
    float angulo = passo;
    float x = 0.0, y = 0.0;

    //modo de pintura do objeto
    glShadeModel(GL_FLAT);

    glBegin(GL_POLYGON);
        glColor3f(vermelho, verde, azul);
        for (i = 0; i < definicao; i++) {
            x = raio * cos(angulo) + x0;
            y = raio * sin(angulo) + y0;

            glVertex2f(x, y);

            angulo += passo;
        }
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); //rgba
}

void renderizar() {
    //limpar tela
    glClear(GL_COLOR_BUFFER_BIT);

    //desenha o primeiro circulo
    desenharCirculo(0.2, 0, 0, 30, 0.898, 0.454, 0.043);
    desenharCirculo(0.15, 0.2, 0, 30, 0.011, 0.329, 0.027);
    desenharCirculo(0.15, -0.2, 0, 30, 1.0, 0, 0);
    desenharCirculo(0.15, 0, 0.2, 30, 0.984, 0.866, 0.015);
    desenharCirculo(0.15, 0, -0.2, 30, 0, 0, 1.0);
    //liberacao de memoria
    glFlush();
}

int main(int argc, const char* argv[]) {
    //linux
    glutInit(&argc, (char**) argv);

    //configuracao e exibicao do modo grafico
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Desenhando circulo com OpenGL");

    //registra a funcao de renderizacao
    glutDisplayFunc(renderizar);

    //inicializacao do ambiente
    init();

    //loop de tratamento de eventos
    glutMainLoop();

    return 0;
}