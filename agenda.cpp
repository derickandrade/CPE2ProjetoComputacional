#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

//
struct Contato {
    string nome;
    string email;
    string telefone;
    string endereco;
};

vector<struct Contato> lista;

//esses valores têm que ser sempre ímpares pra centralizar certinho
int maiorNome = 15;
int maiorEmail = 21;
int maiorEndereco = 17;
int antigoMaiorNome = 15;
int antigoMaiorEmail = 21;
int antigoMaiorEndereco = 17;

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


void adicionarContato(){
    //pra tabela de contatos funcionar direito, nessa função tem que verificar se o tamanho do nome, do email e do endereço são maiores que as variáveis globais "maiorNome", "maiorEmail" e "maiorTelefone"
    //quando for atribuir o tamanho do maior nome, email e telefone, verificar se eles são pares, se forem soma 1
    //antes de atribuir os novos valores maiores, salva os antigos nas variaveis antigoMaiorX 
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

}

void salvarContatosArquivo(){

}

int main(){
    Contato pessoa;
    pessoa.nome = "Joao da Silva";
    pessoa.telefone = "(61)90000-0000";
    pessoa.email = "joaodasilva@email.com";
    pessoa.endereco = "exemplo endereço";
    lista.push_back(pessoa);

    pessoa.nome = "Joao";
    pessoa.telefone = "(61)90000-0000";
    pessoa.email = "joao@email.com";
    pessoa.endereco = "exemploendereço";
    lista.push_back(pessoa);

    pessoa.nome = "Jo";
    pessoa.telefone = "(61)90000-0000";
    pessoa.email = "jo@email.com";
    pessoa.endereco = "exemplo";
    lista.push_back(pessoa);
    exibirLista();
    return 0;
}