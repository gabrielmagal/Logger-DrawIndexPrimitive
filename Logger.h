int index = 0; // Aqui temos o Index que será responsável por navegar entre os logs encontrados
int countLogs = 0; // Irá armazenar quantos logs temos
UINT SaveLogs[1000] = { '\0' }; // Criamos uma váriavel para armazenar todos logs

void DrawIndexLogger(UINT varLog) {
	if (GetAsyncKeyState(VK_UP) & 1) {
		// Limpamos os valores para dar um Refresh
		system("cls");
		// Se o Index for maior que 1, ele voltará para o Log anterior
		if(index > 1) index--;
		// Como limpamos a tela acima para atualizar onde o Index está, agora é hora de colocar os valores em sua posição novamente...
		for (int i = 1; i <= countLogs; i++) {
			// Printamos na tela os valores atualizados
			printf_s("Novo Valor: [%d]%d\n", countLogs, varLog);
		}
		// Aqui ele irá mostrar o novo Index
		printf_s("====================> Index: [%d]%d\n", index,SaveLogs[index]);
	}

	if (GetAsyncKeyState(VK_DOWN) & 1) {
		// Limpamos os valores para dar um Refresh
		system("cls");
		// Se o Index for menor que o valor máximo, ele irá pular para o próximo log
		if(index < countLogs) index++;
		// Como limpamos a tela acima para atualizar onde o Index está, agora é hora de colocar os valores em sua posição novamente...
		for (int i = 1; i <= countLogs; i++) { 
			// Printamos na tela os valores atualizados
			printf_s("Novo Valor: [%d]%d\n", countLogs, varLog);
		}
		// Aqui ele irá mostrar o novo Index
		printf_s("====================> Index: [%d]%d\n", index, SaveLogs[index]);
	}

	for (int i = 0; i <= countLogs; i++) {
		// Essa parte fica responsável por verificar se o Log é 0 ou se ele já está na lista, caso esteja, vai retornar a função...
		if (varLog == 0 || varLog == SaveLogs[i])
			return;
	}
	// Caso não tenha encontrado valor repetido acima, ele irá acrescentar 1 novo valor na lista de Logs
	SaveLogs[countLogs + 1] = varLog;
	// Acrescentamos o Count porque acabamos de adicionar um novo valor a lista...
	countLogs++;
	// Printamos o valor novo na tela...
	printf_s("Novo Valor: [%d]%d\n", countLogs, varLog);
}


/*
Já na DIP, Utilize dessa forma para obter os Strides:
DrawIndexLogger(Stride);
if (Stride == SaveLogs[index])
{
    // Aqui a cor
}

*/