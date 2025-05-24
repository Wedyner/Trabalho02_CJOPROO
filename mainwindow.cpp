#include "mainwindow.h"
#include "ui_mainwindow.h"  // Inclui a interface gerada pelo Qt

/*
 * Construtor da MainWindow
 * Parâmetro:
 *   - parent: Widget pai (opcional)
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)    // Chama o construtor da classe base
    , ui(new Ui::MainWindow) // Cria a instância da interface de usuário
{
    ui->setupUi(this);       // Configura a interface definida no arquivo .ui

    // Configurações iniciais da janela
    setWindowTitle("Cadastro de Clientes");  // Define o título da janela

    // Estiliza a label de mensagem (verde e negrito)
    ui->lblMensagem->setStyleSheet("QLabel { color: green; font-weight: bold; }");
}

/*
 * Destrutor da MainWindow
 * Libera os recursos alocados
 */
MainWindow::~MainWindow()
{
    delete ui;  // Deleta a interface de usuário
}

/*
 * Função: validarCampos
 * Valida os campos do formulário de cadastro
 * Retorno:
 *   - bool: true se todos os campos são válidos, false caso contrário
 */
bool MainWindow::validarCampos()
{
    // Valida campo Nome (não pode estar vazio)
    if (ui->txtNome->text().isEmpty()) {
        QMessageBox::warning(this, "Atenção", "O campo Nome é obrigatório!");
        ui->txtNome->setFocus();  // Coloca o foco no campo
        return false;
    }

    // Valida campo Email (não pode estar vazio)
    if (ui->txtEmail->text().isEmpty()) {
        QMessageBox::warning(this, "Atenção", "O campo Email é obrigatório!");
        ui->txtEmail->setFocus();
        return false;
    }

    // Valida campo Telefone (não pode estar vazio)
    if (ui->txtTelefone->text().isEmpty()) {
        QMessageBox::warning(this, "Atenção", "O campo Telefone é obrigatório!");
        ui->txtTelefone->setFocus();
        return false;
    }

    // Validação simples de formato de email (deve conter @ e .)
    if (!ui->txtEmail->text().contains('@') || !ui->txtEmail->text().contains('.')) {
        QMessageBox::warning(this, "Atenção", "Por favor, insira um email válido!");
        ui->txtEmail->setFocus();
        return false;
    }

    return true;  // Todos os campos são válidos
}

/*
 * Slot: on_btnEnviar_clicked()
 * Executado quando o botão Enviar é clicado
 */
void MainWindow::on_btnEnviar_clicked()
{
    // Primeiro valida todos os campos
    if (validarCampos()) {
        // Obtém o nome digitado
        QString nome = ui->txtNome->text();

        // Cria mensagem de confirmação personalizada
        QString mensagem = QString("Olá, %1!\nSeu cadastro foi enviado com sucesso!").arg(nome);

        // Exibe a mensagem na label
        ui->lblMensagem->setText(mensagem);

        // Ponto para extensão:
        // Aqui você poderia adicionar código para salvar os dados:
        // - Em um banco de dados
        // - Em um arquivo
        // - Enviar para um servidor
    }
}

/*
 * Slot: on_btnLimpar_clicked()
 * Executado quando o botão Limpar é clicado
 */
void MainWindow::on_btnLimpar_clicked()
{
    // Limpa todos os campos do formulário
    ui->txtNome->clear();
    ui->txtEmail->clear();
    ui->txtTelefone->clear();
    ui->txtEndereco->clear();

    // Limpa a mensagem de status
    ui->lblMensagem->clear();

    // Coloca o foco no campo Nome
    ui->txtNome->setFocus();
}
