/*
 * Arquivo: mainwindow.h
 * Definição da classe principal da aplicação
 *
 * Este arquivo contém a declaração da classe MainWindow que gerencia
 * a interface gráfica e as funcionalidades principais do programa
 */

// Guarda de inclusão (previne múltiplas inclusões do mesmo arquivo)
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// Inclusão das classes necessárias do Qt
#include <QMainWindow>      // Classe base para janelas principais
#include <QMessageBox>      // Para exibir caixas de mensagem

// Início do namespace do Qt
QT_BEGIN_NAMESPACE
// Declaração antecipada da classe de interface (gerada pelo Qt Designer)
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*
 * Classe: MainWindow
 * Janela principal da aplicação que herda de QMainWindow
 *
 * Responsável por:
 * - Gerenciar a interface do usuário
 * - Processar eventos dos botões
 * - Validar dados de entrada
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT  // Macro necessária para usar recursos Qt como signals/slots

public:
    // Construtor da classe
    // Parâmetro:
    //   - parent: Widget pai (opcional, padrão nullptr)
    MainWindow(QWidget *parent = nullptr);

    // Destrutor da classe
    ~MainWindow();

private slots:  // Seção para slots (métodos que respondem a eventos)
    // Slot para o evento de clique no botão Enviar
    void on_btnEnviar_clicked();

    // Slot para o evento de clique no botão Limpar
    void on_btnLimpar_clicked();

private:  // Membros privados (implementação interna)
    // Ponteiro para a interface de usuário (gerada pelo Qt Designer)
    Ui::MainWindow *ui;

    /*
     * Função: validarCampos
     * Valida os dados inseridos nos campos do formulário
     * Retorno:
     *   - bool: true se todos os campos são válidos, false caso contrário
     */
    bool validarCampos();
};

// Fim da guarda de inclusão
#endif // MAINWINDOW_H
