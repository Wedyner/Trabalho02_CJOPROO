/*
 * Arquivo: main.cpp
 * Ponto de entrada principal da aplicação Qt
 *
 * Responsável por iniciar o aplicativo e configurar a janela principal
 */

// Inclui o cabeçalho da janela principal da aplicação
#include "mainwindow.h"
// Inclui a classe QApplication que gerencia o aplicativo Qt
#include <QApplication>

/*
 * Função: main
 * Ponto de entrada do programa (executado quando o aplicativo inicia)
 *
 * Parâmetros:
 *   - argc: Contador de argumentos da linha de comando
 *   - argv: Array de strings com os argumentos passados
 *
 * Retorno:
 *   - int: Código de status de saída (0 para sucesso)
 */
int main(int argc, char *argv[])
{
    // 1. Cria a instância do aplicativo Qt (obrigatório)
    // - Gerencia o loop principal de eventos
    // - Processa argumentos da linha de comando
    QApplication a(argc, argv);

    // 2. Cria a instância da janela principal
    // - MainWindow é a classe definida em mainwindow.h
    // - Será destruída automaticamente quando o app terminar
    MainWindow w;

    // 3. Exibe a janela principal
    // - Torna a janela visível na tela
    // - Equivalente a w.setVisible(true)
    w.show();

    // 4. Inicia o loop principal de eventos
    // - Mantém o aplicativo rodando
    // - Processa interações do usuário (cliques, teclas, etc.)
    // - Retorna quando a janela principal é fechada
    return a.exec();

    /*
     * Fluxo completo de execução:
     * 1. QApplication é inicializada com os parâmetros do sistema
     * 2. A janela principal é criada (construtor é executado)
     * 3. A janela é exibida na tela com show()
     * 4. a.exec() inicia o loop de eventos:
     *    - Fica aguardando interações do usuário
     *    - Distribui eventos para os componentes apropriados
     *    - Mantém o app ativo até a janela ser fechada
     * 5. Quando a janela fecha, exec() retorna
     * 6. O programa termina retornando o código de saída
     */
}
