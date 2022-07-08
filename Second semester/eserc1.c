/*Scrivere un programma C che richiede all’utente di inserire due date e calcola il numero di giorni trascorsi tra di esse.
¢ Si dovrà dichiarare il tipo di dato date
¢ Il programma deve comprendere le funzioni:  date insertDate(): richiede all’utente di inserire una data e restituisce la corrispondente struttura.
Se la data inserita non è valida viene richiesta di nuovo.
 int checkDate( date d ): verifica se la data d è valida.
 int elapsedDays(date d1, date d2): calcola i giorni trascorsi tra d1 e d2. */

#include<stdio.h>

/*************************************************************************************************************************************************************
	C'E' UN QUALCHE ERRORE DA QUALCHE PARTE, IL CONTEGGIO SI AVVICINA MOLTO ALLA REALTA' MA SBAGLIA DI POCHI GIORNI
	FORSE DIPENDE DA UN ERRATO CONTEGGIO DEI BISESTILI?
*********************************************************************************************************************************************************/

typedef struct{
    int day;
    int month;
    int year;
}date;

int dayscounter(date, date);
int bisestiledate(date);
int bisestileint(int);
int annocorretto(date);

void main(){
    date a, b;
    int total;

	//Chiedo la prima data
    printf("Inserisci la prima data:\nGiorno: ");
    do{
	    do{
	        scanf("%d",&a.day);
	    }while(a.day<1||a.day>31);
	    printf("Mese: ");
	    do{
	        scanf("%d",&a.month);
	    }while(a.month<1||a.month>12);
	    printf("Anno (dal 1200 in poi): ");
	    do{
	        scanf("%d",&a.year);
	    }while(a.year<1200||a.year>2022);
	    if(!annocorretto(a))
	    	printf("Data errata, inserisci nuovamente la prima data: ");
	}while(!annocorretto(a)); //ripeto finch� l'anno non � corretto

	//Chiedo la seconda data
    do{
    	do{
	        printf("Inserisci la seconda data:\nGiorno: ");
	        do{
	            scanf("%d",&b.day);
	        }while(b.day<1||b.day>31);
	        printf("Mese: ");
	        do{
	            scanf("%d",&b.month);
	        }while(b.month<1||b.month>12);
	        printf("Anno (dal 1200 in poi): ");
	        do{
	            scanf("%d",&b.year);
	        }while(b.year<1200||b.year>2022);
	    	if(!annocorretto(b))
	    		printf("Data errata, inserisci nuovamente la seconda data: ");
        }while(!annocorretto(b));
        
        if(b.year<a.year||((b.year==a.year)&&b.month<a.month)||((b.year==a.year)&&(b.month==a.month)&&b.day<a.day))
            printf("Il secondo anno dev'essere successivo al primo.\n");
    }while(b.year<a.year||((b.year==a.year)&&b.month<a.month)||((b.year==a.year)&&(b.month==a.month)&&b.day<a.day)); //ripeto se data2 non � successivo a data1

    printf("Anno 1: %02d/%02d/%4d\n",a.day,a.month,a.year);
    printf("Anno 2: %02d/%02d/%4d\n",b.day,b.month,b.year);

    total=dayscounter(a,b);
    
    printf("Tra il %02d/%02d/%4d e il %02d/%02d/%4d ci sono %d giorni.\n", a.day, a.month, a.year, b.day, b.month, b.year, total);

}

int dayscounter(date data1, date data2){
    int indexd, indexm, indexy;
    int totale=0, primo;
    int annoinmezzo;

    
	if(data2.year==data1.year){  //CONTEGGIO SE ANNO 1 E' UGUALE AD ANNO 2
		if(data1.month==data2.month) //se nello stesso mese
			totale+=(data2.day-data1.day);
		else{
	    	primo=1;
		    for(indexm=data1.month;indexm<data2.month;indexm++){ //passo i mesi da quello di data1 a quello di data2
		    	if(primo){ //se � il primo mese che sto considerando
			        if(indexm==2){ //se febbraio
			        	if(bisestiledate(data1)) //e bisestile
			            	for(indexd=data1.day;indexd<30;indexd++) //conto i giorni da quello della data a 29
			              	  totale++;
			            else //se non bisestile
			            	for(indexd=data1.day;indexd<29;indexd++) //conto i giorni da quello della data a 28
			              	  totale++;
			            primo=0;
			        }
			        if(indexm==11||indexm==4||indexm==6||indexm==9){ //se mese da 30gg
			            for(indexd=data1.day;indexd<31;indexd++)
			                totale++;
			            primo=0;
			        }
			        else{ //altrimenti il mese è da 31gg
			            for(indexd=data1.day;indexd<32;indexd++)
			                totale++;
			            primo=0;
			        }
		        }
		    	else{ //se NON � il primo mese che sto considerando
			        if(indexm==2) //se febbraio
			        	if(bisestiledate(data1)) //e bisestile
			            	totale+=29; //aggiungo 29 giorni
			            else //se non bisestile
			            	totale+=28; // aggiungo 28 giorni
			        if(indexm==11||indexm==4||indexm==6||indexm==9) //se mese da 30gg
			            totale+=30;
			        else //altrimenti il mese è da 31gg
			            totale+=31;
	        	}
			}
		    for(indexd=data2.day;indexd>1;indexd--) //conto i giorni dell'ultimo mese
		    	totale++;
		}
	}
	
	else{ //SE ANNO 1 NON E' UGUALE AD ANNO 2
	    //CONTO I GIORNI DEL PRIMO ANNO
	    primo=1;
	    for(indexm=data1.month;indexm<13;indexm++){ //passo i mesi della data 1
	    	if(primo){ //se � il primo mese che sto considerando
		        if(indexm==2){ //se febbraio
		        	if(bisestiledate(data1)) //e bisestile
		            	for(indexd=data1.day;indexd<30;indexd++) //conto i giorni da quello della data a 29
		              	  totale++;
		            else //se non bisestile
		            	for(indexd=data1.day;indexd<29;indexd++) //conto i giorni da quello della data a 28
		              	  totale++;
		            primo=0;
		        }
		        if(indexm==11||indexm==4||indexm==6||indexm==9){ //se mese da 30gg
		            for(indexd=data1.day;indexd<31;indexd++)
		                totale++;
		            primo=0;
		        }
		        else{ //altrimenti il mese è da 31gg
		            for(indexd=data1.day;indexd<32;indexd++)
		                totale++;
		            primo=0;
		        }
	        }
	    	else{ //se NON � il primo mese che sto considerando
		        if(indexm==2) //se febbraio
		        	if(bisestiledate(data1)) //e bisestile
		            	totale+=29; //aggiungo 29 giorni
		            else //se non bisestile
		            	totale+=28; // aggiungo 28 giorni
		        if(indexm==11||indexm==4||indexm==6||indexm==9) //se mese da 30gg
		            totale+=30;
		        else //altrimenti il mese è da 31gg
		            totale+=31;
	        }
	    }
	
	    //CONTO I GIORNI DELL'ULTIMO ANNO
	    primo=1;
	    for(indexm=data2.month;indexm>0;indexm--){ //passo i mesi della data 2
	    	if(primo){ //se � il primo mese che sto considerando
		        for(indexd=data2.day;indexd>0;indexd--) //conto i giorni da quello della data ad 1
		        	totale++;
		        primo=0;
		    }
	    	else{ //se NON � il primo mese che sto considerando
		        if(indexm==2) //se febbraio
		        	if(bisestiledate(data2)) //e bisestile
		            	totale+=29; //aggiungo 29 giorni
		            else //se non bisestile
		            	totale+=28; //aggiungo 28 giorni
		        if(indexm==11||indexm==4||indexm==6||indexm==9) //se mese da 30gg
					totale+=30;
		        else //altrimenti il mese è da 31gg
		            totale+=31;
	        }
	    }
	}

	if(data2.year-data1.year>1) //se ci sono altri anni in mezzo
		for(annoinmezzo=data1.year+1;annoinmezzo<data2.year;annoinmezzo++)
			if(bisestileint(annoinmezzo))
				totale+=366;
			else
				totale+=365;
    
    return totale;
}


int bisestiledate(date y){
	if((y.year%4==0&&y.year%100!=0)||y.year%400==0)
		return 1;
  	else 
   		return 0;
}

int bisestileint(int y){
	if((y%4==0&&y%100!=0)||y%400==0)
		return 1;
  	else 
   		return 0;
}

int annocorretto(date anno){
	if(bisestiledate(anno)){
		if(anno.month==2&&anno.day>29)
			return 0;
	}
	else
		if(anno.month==2&&anno.day>28)
			return 0;
	
	if((anno.month==11||anno.month==4||anno.month==6||anno.month==9)&&anno.day>30)
		return 0;
	
	else if(anno.day>31)
		return 0;
		
	return 1;
}













