#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//
struct Contato {
    string nome;
    string email;
    string telefone;
    string endereco;
};

vector<struct Contato> lista;

// Essa flag global serve pra indicar se o contato foi encontrado nas pesquisas em outras funções
bool encontrado = false;

//esses valores têm que ser sempre ímpares pra centralizar certinho
int maiorNome = 0;
int maiorEmail = 0;
int maiorEndereco = 0;

void exibirLista(){
    system("cls"); //isso limpa o terminal

    //IMPRIMINDO O CABEÇALHO
    //metade da coluna fica com espaços, baseado no tamanho do maior nome da lista
    for (int i = 0; i < (maiorNome / 2) - 2; i++){ 
        printf(" ");
    }
    //no meio tem Nome
    printf("Nome");
    //preenche a outra metade com espaços
    for (int i = 0; i < (maiorNome / 2) - 2; i++){
        printf(" ");
    }

    printf(" ||    Telefone    || ");
    for (int i = 0; i < (maiorEmail / 2) - 2; i++){
        printf(" ");
    }
    printf("E-mail");
    for (int i = 0; i < (maiorEmail / 2) - 2; i++){
        printf(" ");
    }
    printf(" || ");
    for (int i = 0; i < (maiorEndereco / 2) - 4; i++){
        printf(" ");
    }
    printf("Endereço");
    for (int i = 0; i < (maiorEndereco / 2) - 4; i++){
        printf(" ");
    }
    printf("\n");

    //linhas horizontais pra separar o cabeçalho dos contatos
    for (int i = 0; i < (maiorNome + maiorEmail + maiorEndereco + 26); i++){ //26 = tamanho telefone + espaços + barras verticais
        printf("=");
    }
    printf("\n");

    for (Contato contato : lista){
        
        cout << contato.nome;
        
        //se o nome impresso for menor que o maior nome, preenche o resto com espaços
        if (contato.nome.length() < maiorNome){
            for (int i = 0; i < maiorNome - contato.nome.length(); i++){
                cout << " ";
            }
        }
        //todos os telefones têm o mesmo tamanho
        cout << "|| " << contato.telefone;
        
        cout << " || " << contato.email;

        if (contato.email.length() < maiorEmail){
            for (int i = 0; i < maiorEmail - contato.email.length(); i++){
                cout << " ";
            }
        }

        cout << "  || " << contato.endereco << "\n";
        
    }
}

// Entra na tela de adicionar um contato, pede as informações nome, telefone, e-mail e endereço, cria o contato a partir destas e guarda na lista de contatos
// Verifica se a informação inserida tem mais caracteres que a última maior informação para formatar a tabela e garante que esse número seja ímpar para melhor centralização
void adicionarContato(){        
    Contato temp;    
    cout << "Nome: ";
    string input;        
    
    getline(cin, input);    
    
    if (input.length() > maiorNome){
        maiorNome = input.length();
        if (input.length() % 2 == 0)
            maiorNome++;                
    }
    temp.nome = input;

    cout << "Telefone: ";        
    getline(cin, input);
    temp.telefone = input;

    cout << "E-Mail: ";
        
    getline(cin, input);
    if (input.length() > maiorEmail){
        maiorEmail = input.length();
        if (input.length() % 2 == 0) 
            maiorEmail++;        
    }
    temp.email = input;
    
    cout << "Endereço: ";    
    getline(cin, input);
    if (input.length() > maiorEndereco){
        maiorEndereco = input.length();
        if (input.length() % 2 == 0)
            maiorEndereco++;
    }
    temp.endereco = input;

    lista.push_back(temp);    
    cout << "Contato adicionado com sucesso!\n\nPressione ENTER para continuar...";
    cin.ignore();
    system("cls");
}

void pesquisarContatoNome(){

}

void pesquisarContatoTelefone(){

}

void pesquisarContatoEmail(){

}

void pesquisarContatoEndereco(){

}

void editarContatoNome(){

}

void editarContatoTelefone(){

}

void editarContatoEmail(){

}

void editarContatoEndereco(){

}

void apagarContato(){
    //quando apagar um contato, atribui os valores antigoMaiorX nas variaveis maiorX
}

void carregarContatosArquivo(){
    ifstream myfile;
    string s;
    myfile.open("agenda.txt");
    if (!myfile.is_open()){
        cout << "Erro ao carregar os contatos.\nReinicie o programa.";
        while(true){            
        }
    }
    int cont = 0;
    int linha = 0;
    Contato addContato;
    while (getline(myfile, s)){        
        if (cont > 2){
            if (linha == 0){
                addContato.nome = s;
                linha = 1;
            }
            else if (linha == 1){
                addContato.telefone = s;
                linha = 2;
            }
            else if (linha == 2) {
                addContato.email = s;
                linha = 3;
            }
            else {
                addContato.endereco = s;
                lista.push_back(addContato);
                linha = 0;
            }
        }
        else if (cont == 0){
            maiorNome = stoi(s);
            cont++;
        }
        else if (cont == 1) {
            maiorEmail = stoi(s);
            cont++;
        }
        else if (cont == 2) {
            maiorEndereco = stoi(s);
            cont++;
        }
    }
    myfile.close();
}

void salvarContatosArquivo(){
    ofstream myfile;
    myfile.open("agenda.txt", ios::trunc);
    myfile << maiorNome << '\n';
    myfile << maiorEmail << '\n';
    myfile << maiorEndereco << '\n';

    for (Contato contato : lista) {
        myfile << contato.nome << '\n';
        myfile << contato.telefone << '\n';
        myfile << contato.email << '\n';
        myfile << contato.endereco << '\n';
    }
    
    myfile.close();
}

void menuEdicao(Contato* _pessoa) {
    int escolha;
    system("cls");
    cout << "Nome: " << _pessoa->nome
    << "\nTelefone: " << _pessoa->telefone
    << "\nE-Mail: " << _pessoa->email
    << "\nEndereço: " << _pessoa->endereco << '\n';
    cout << "Escolha uma opção:\n0 - Voltar ao menu principal\n1 - Editar nome\n2 - Editar telefone\n3 - Editar e-mail\n4 - Editar endereço\n5 - Excluir contato\n";
    cin >> escolha;
    cin.ignore();    
    switch (escolha) {
        case 0:
            break;
        case 1:
            editarContatoNome(_pessoa);
            break;
        case 2:
            editarContatoTelefone(_pessoa);
            break;
        case 3:
            editarContatoEmail(_pessoa);
            break;
        case 4:
            editarContatoEndereco(_pessoa);
            break;
        case 5:
            apagarContato(_pessoa);
            break;
    }
}

void menuPesquisa(){
    int escolha;
    system("cls");
    cout << "Escolha uma opção:\n0 - Voltar ao menu principal\n1 - Pesquisar por nome\n2 - Pesquisar por telefone\n3- Pesquisar por e-mail\n4 - Pesquisar por endereço\n";
    cin >> escolha;        
    Contato *_pessoa;
    switch (escolha) {
        case 0:
            break;
        case 1:
            pesquisarContatoNome(_pessoa);                        
            break;
        case 2:
            pesquisarContatoTelefone(_pessoa);
            break;
        case 3:
            pesquisarContatoEmail(_pessoa);
            break;
        case 4:
            pesquisarContatoEndereco(_pessoa);
            break;
    }
    
    if (encontrado){        
        menuEdicao(_pessoa);
    }
    else {
        cout << "Nenhum contato encontrado\nPressione ENTER para voltar ao menu";
        cin.ignore();
        system("cls");
    }
}

int main(){
    int escolha;
    bool continuar = true;
    carregarContatosArquivo();
    while (continuar){
        cout << "Escolha uma opção:\n"
        "0 - Encerrar o programa\n"
        "1 - Exibir lista de contatos\n"
        "2 - Adicionar novo contato\n"
        "3 - Pesquisar um contato\n";
        cin >> escolha;
        cin.ignore();
        switch (escolha) {
            case 0:   
                continuar = false;
                salvarContatosArquivo();             
                break;
            case 1:
                exibirLista();
                break;
            case 2:
                adicionarContato();
                break;
            case 3:
                menuPesquisa();
                break;
        }
    }
    return 0;
}