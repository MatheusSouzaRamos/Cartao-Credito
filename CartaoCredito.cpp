#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Divida{
	private:
		string tipo;
		float valor;
	public:
		Divida(){
			tipo = "não informado";
			valor = 0;
		}
		
		Divida(string tipo, float valor){
			this->tipo = tipo;
			this->valor = valor;		
		}
		
		~Divida(){}
		
		void set(){
			cout << "\nNome da compra: ";
			getline(cin,tipo);
			cout << "Valor da compra: ";
			cin >> valor;
			cin.ignore();
		}
		
		void print(){
			cout << "\nNome da compra: " << tipo;
			cout << "\nValor da compra: R$" << valor;
		}
		
		float retvalor(){
			return valor;
		}
		
}; // classe divida

class Cliente{
	private:
		string nome;
		int idade;
		deque<Divida> boletos;
	public:
		Cliente(){
			nome = "não informado";
			idade = 0;
		}
		
		Cliente(string nome, int idade){
			this->nome = nome;
			this->idade = idade;
		}
		
		~Cliente(){}
		
		
		void set(){
			cout << "\nNome: ";
			getline(cin,nome);
			cout << "Idade: ";
			cin >> idade;
			cin.ignore();
		}
		
		void print(){
			cout << "\nNome: " << nome;
			cout << "\nIdade: " << idade;
		}
		
		string retnome(){
			return nome;
		}
		
		int retidade(){
			return idade;
		}
		
		void setDivida(){
			
			char r;	
			do{
				Divida A;
				A.set();
				boletos.push_front(A);
				cout << "\nCompra Efetuada!\nRealizar outra compra? ";
				cin >> r;
				cin.ignore();	
			}while(r=='s');
			
		}
		
		void setDividaLoja(string tipo, float valor){
			Divida A(tipo,valor);
			boletos.push_back(A);	
		}
		
		void printBoletos(){
			deque<Divida> B;
			B = boletos;
			
			while(!B.empty()){
				B.front().print();
				cout << endl;
				B.pop_front();
			}	
		}
		
		float rettotal(){
			float total = 0;
			deque<Divida> B;
			B = boletos;
			
			while(!B.empty()){
				total = total + B.front().retvalor();
				B.pop_front();
			}
			
			return total;
		}
			
}; // class cliente

class Loja{
	private:
		string nome;
		string nomeproduto;
		float valor;
		deque<Cliente> clientes;
	public:
		Loja(){
			nome = "não informado";
			nomeproduto = "não informado";
			valor = 0;
		}
		
		~Loja(){}
		
		void set(){
			cout << "\nNome da Loja: ";
			getline(cin,nome);
			cout << "Nome do Produto desta loja: ";
			getline(cin,nomeproduto);
			cout << "Valor do produto desta loja: ";
			cin >> valor;
			cin.ignore();
		}
		
		void cadCliente(string nomeCliente, int idadeCliente){
			Cliente A(nomeCliente,idadeCliente);
			clientes.push_back(A);
		}
		
		void print(){
			cout << "\nNome da Loja: " << nome;
			cout << "\nProduto da Loja: " << nomeproduto;
			cout << "\nValor do Produto: " << valor; 
		}
		
		void printClientes(){
			deque<Cliente> C;
			C = clientes;
			
			while(!C.empty()){
				cout << C.front().retnome() << endl;
				C.pop_front();
			}
		}
		
		deque<Cliente> retClientes(){
			deque<Cliente> A;
			A = clientes;
			return A;
		}
		
		string retProduto(){
			return nomeproduto;
		}
		
		float retValor(){
			return valor;
		}
		
		string retnome(){
			return nome;
		}
		
}; // class loja


int main(){
	
	deque<Cliente> pessoas, y, retclientes;
	deque<Loja> lojas, z;
	char r, op, op2;
	string nome, nome2;
	int count, count2;
	Cliente w;
	
	do{
		system("clear");
		cout << "============ CARTÃO ============";
		cout << "\n[1] - Cadastro de Cliente\n[2] - Listagem de Clientes Cadastrados";
		cout << "\n[3] - Cadastros de lojas\n[4] - Listagem de Lojas";
		cout << "\n[5] - Cadastrar Cliente a uma Loja \n[6] - Efetuar Compras";
		cout << "\n[7] - Fatura de Clientes\n[0] - Sair do Programa";
		cout << "\nO que deseja fazer? \n--> ";
		cin >> op;
		cin.ignore();
		
		switch(op){
			case '1':
				do{
					system("clear");
					cout <<"==== CADASTRO DE CLIENTE ====";
					Cliente x;
					x.set();
					pessoas.push_back(x);
					cout << "\nCliente Cadastrado!\nDejesa cadastrar outro cliente? ";
					cin >> r;
					cin.ignore();	
				}while(r=='s');
			break;
			
			case '2':
				system("clear");
				cout << "==== Clientes Cadastradas ====";
				y = pessoas;
				while(!y.empty()){
					y.front().print();
					y.pop_front();
					cout << endl;
				}
				getchar();
			break;
			
			case '3':
				system("clear");
				cout << "=== Cadastro de Lojas ===";
				do{
					Loja x;
					x.set();
					lojas.push_back(x);
					cout << "\nLoja cadastrada!\ncadastrar outra loja? ";
					cin >> r;
					cin.ignore();
					system("clear");	
				}while(r=='s');
			break;
				
			case '4':
				system("clear");
				cout << "=== Lojas Cadastradas ===";
				z = lojas;
				while(!z.empty()){
					z.front().print();
					z.pop_front();
					cout << endl;
				}
				getchar();	
			break;
			
			case '5':
				system("clear");
				if(pessoas.size() > 0 and lojas.size() > 0 ){
					cout << "=== Cadastro de clientes em Lojas ===" << endl << "---- Lojas Cadastradas ----";
					z = lojas;
					while(!z.empty()){
						z.front().print();
						
						if(z.front().retClientes().size() > 0){
							cout << endl << "Clientes cadastrados nesta loja: " << endl;
							z.front().printClientes();
						}
						z.pop_front();
						cout << endl;
					}
					cout << "\n----------";

					count = lojas.size();
					count2 = pessoas.size();
					cout << "\nQual Loja? ";
					getline(cin,nome);
					system("clear");				
					
					for(int i = 0; i < count; i++){
						if(lojas.front().retnome() == nome ){
							cout << "---- Pessoas Cadastradas no Geral ----";
							y = pessoas;
							
							while(!y.empty()){
								y.front().print();
								y.pop_front();
								cout << endl;
							}
						
							cout << "\nQual cliente será cadastrado nesta loja? ";
							getline(cin,nome2);
							
							for(int i = 0; i < count2; i++){
								if(pessoas.front().retnome() == nome2){	
									lojas.front().cadCliente(pessoas.front().retnome(), pessoas.front().retidade());
									cout << "\nCliente Cadastrado!" << endl;
									getchar();
								}
								
								pessoas.push_back(pessoas.front());
								pessoas.pop_front();	
								
							}
							
						}
						
						lojas.push_back(lojas.front());
						lojas.pop_front();	
						
					}
				
				}else{
					cout << "Cadastre Lojas e clientes antes!" << endl;
					getchar();	
				}	
			break;
				
			case '6':
			if(pessoas.size() > 0){
				do{
					system("clear");
					cout << "==== Efutuar Compras ===" << endl << "[1] - Compras Avulsas" << endl;
					cout << "[2] - Compras por Lojas" << endl << "[0] - Voltar ao menu principal" << endl << "--> ";
					cin >> op2;
					cin.ignore();
					
					switch(op2){
						case '1':
							system("clear");
							cout << "=== Compras Avulsas ===\n---- Pessoas Cadastradas ----" << endl;
							y = pessoas;
							count = y.size();
							while(!y.empty()){
								y.front().print();
								y.pop_front();
								cout << endl;
							}
							
							cout << "\nQual Pessoa fará a compra? ";
							getline(cin,nome);
							system("clear");
							cout << "Qual Pessoa fará a compra? " << nome;
							
							for(int i = 0; i < count; i++){
								if(nome == pessoas.front().retnome()){
									pessoas.front().setDivida();
								}
								
								pessoas.push_back(pessoas.front());
								pessoas.pop_front();		
							}
							
						break;
						
						case '2':
						if(lojas.size() > 0){
							system("clear");
							cout << "=== Compras Por Lojas ===" << endl << "--- Lojas Cadastradas ---" << endl;
							z = lojas;
							
							while(!z.empty()){
								z.front().print();
								cout << "\nClientes cadastrados na loja: ";
								z.front().printClientes();
								z.pop_front();
								cout << endl;
							}
							
							cout << "\nQual loja? ";
							getline(cin, nome);
							system("clear");						
							count = lojas.size();
							count2 = pessoas.size();
							
							for(int i = 0; i < count; i++){
								if(lojas.front().retnome() == nome){
									cout << "Loja: " << lojas.front().retnome();
									cout << "\nClientes cadastrados nesta loja:" << endl;
									lojas.front().printClientes();
									cout << endl;
									cout << "\nQual Cliente? ";
									getline(cin,nome2);
									
									retclientes = lojas.front().retClientes();
									
									for(int i = 0; i < retclientes.size(); i++){
										if(retclientes.front().retnome() == nome2){
											for(i = 0; i < count2; i++){
												if(pessoas.front().retnome() == nome2){	
													pessoas.front().setDividaLoja(lojas.front().retProduto(), lojas.front().retValor());
													cout << "\nCOMPRA EFETUADA" << endl;
													getchar();
												}
												
												pessoas.push_back(pessoas.front());
												pessoas.pop_front();
												
											}
											
											retclientes.push_back(retclientes.front());
											retclientes.pop_front();
											
										}
									
									}
									
								}
								
								lojas.push_back(lojas.front());
								lojas.pop_front();
							}
						
						}else{
							system("clear");
							cout << "Cadastre Lojas antes!" << endl;
							getchar();
						}
						break;
						
						default:
						cout << "Opção invalida, tente novamente!\n";
						break;
					}		
				}while(op2 != '0');
			
			}else{
				system("clear");
				cout << "Cadastre clientes antes!" << endl;
				getchar();
			}
			break;
			
			case '7':
				system("clear");
				y = pessoas;
				
				if(!y.empty()){
					system("clear");
					cout << "== Fatura Total de Cliente Cadastrado ==\n--- Lista de Clientes: ---\n";
					
					y = pessoas;
					while(!y.empty()){
						y.front().print();
						y.pop_front();
						cout << endl;
					}
					
					cout << "\nQual cliente deseja? ";
					getline(cin,nome);					
					system("clear");
					cout << "Cliente: " << nome;
					
					count = pessoas.size();
					
					for(int i = 0; i < count; i++){
						if(pessoas.front().retnome() == nome ){
							cout << "\n--- Extrato ---" << endl;
							w = pessoas.front();	
						}
						
						pessoas.push_back(pessoas.front());
						pessoas.pop_front();
						
					}
					
					w.printBoletos();
					cout << "\n\nFatura de " << nome << " = R$" << w.rettotal() << endl;
					getchar();
					
				}else{
					cout << "Sem clientes para consulta!" << endl;
					getchar();
				}
				
			break;
			
			case '0':
			break;
			
			default:
				cout << "Opção invalida, tente novamente!\n";
				getchar();
			break;
		}
		
	}while(op!='0');	

	return 0;
}

