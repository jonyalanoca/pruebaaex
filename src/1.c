#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int id;
	char marca[20];
	int tipo;
	float peso;
}eVeiculo;
eVeiculo* contructorParam(int id, char* marca, int tipo, float peso);
eVeiculo* contructorBase(void);
int veiculo_setId(eVeiculo* this, int id);
int veiculo_setMarca(eVeiculo* this, char* marca);
int veiculo_setTipo(eVeiculo* this , int tipo);
int veiculo_setPeso(eVeiculo* this, float peso);
int guardarEnTexto(eVeiculo* this, char* path);
int guardarEnBinario(eVeiculo* this, char* path);
int main(void) {
	setbuf(stdout,NULL);
	eVeiculo* noas;
	noas=contructorParam(12,"jony",123,12.4);
	printf("%d %s %d %f",noas->id, noas->marca, noas->tipo, noas->peso);
	guardarEnTexto(noas,"jony.txt");
	guardarEnBinario(noas,"jony.bin");
	return EXIT_SUCCESS;
}
eVeiculo* contructorBase(void){
	eVeiculo* aux;
	aux=(eVeiculo*)malloc(sizeof(eVeiculo));
	if(aux==NULL){
		printf("No se puedo dar memoria.\n");
		exit(1);
	}


	return aux;
}
eVeiculo* contructorParam(int id, char* marca, int tipo, float peso){
	eVeiculo* aux;
	aux=contructorBase();
	veiculo_setId(aux,id);
	veiculo_setMarca(aux,marca);
	veiculo_setTipo(aux,tipo);
	veiculo_setPeso(aux,peso);
	return aux;
}
int veiculo_setId(eVeiculo* this, int id){
	int todoOK=-1;
	if(this!=NULL && id>0){
		this->id=id;
		todoOK=0;
	}
	return todoOK;
}
int veiculo_setMarca(eVeiculo* this, char* marca){
	int todoOK=-1;
	if(this!=NULL && marca!=NULL){
		strcpy(this->marca,marca);
		todoOK=0;
	}
	return todoOK;
}
int veiculo_setTipo(eVeiculo* this , int tipo){
	int todoOK=-1;
	if(this!=NULL &&tipo>0){
		this->tipo=tipo;
		todoOK=0;
	}
	return todoOK;
}
int veiculo_setPeso(eVeiculo* this, float peso){
	int todoOK=-1;
	if(this!=NULL &&peso>0){
		this->peso=peso;
		todoOK=0;
	}
	return todoOK;
}
int guardarEnTexto(eVeiculo* this, char* path){
	int todoOK=-1;
	if(this!=NULL && path !=NULL){
		FILE* file=fopen(path, "w");
		fprintf(file,"%d,%s,%d,%.2f\n",this->id,this->marca, this->tipo, this->peso);
		fclose(file);
		todoOK=0;
	}
	return todoOK;
}
int guardarEnBinario(eVeiculo* this, char* path){
	int todoOK=-1;
	if(this!=NULL && path !=NULL){
		FILE* file=fopen(path, "wb");
		fwrite(this,sizeof(eVeiculo),1,file);
		fclose(file);
		todoOK=0;
	}
	return todoOK;
}

