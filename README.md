## Crud simples em C com um exportador de CSV

CRUD completo(Cadastrar, listar, editar e excluir) com uma opção de exportar um CSV gerado automaticamente pelo programa!

## Funcionalidades
- Cadastrar clientes (nome, data nascimento, CPF)

- Listar todos os clientes cadastrados

- Editar dados de clientes existentes

- Excluir clientes 

- Exportar lista para um arquivo CSV

## Menu interativo:

=== Cadastro de Clientes ===  
1 - Cadastrar cliente     
2 - Listar clientes   
3 - Editar cliente  
4 - Excluir cliente  
5 - Exportar CSV  
6 - Sair  

## Exemplo de Uso

Digite o nome do cliente: João Silva
Digite a data de nascimento (dd mm aaaa): 15 08 1990
Digite o CPF: 123.456.789-00
Cliente cadastrado com sucesso.

## CSV gerado:

Nome,Data_nascimento,CPF
João Silva,15/08/1990,123.456.789-00

## Compilar o programa:

bash
gcc -o clientecomcsv clientes.c
Executar:
bash
./clientecomcsv










