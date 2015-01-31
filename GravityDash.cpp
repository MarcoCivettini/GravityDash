/*//////////       /////////   //////////   //      //  //  //////////   //
//               //     //   //      //   //      //  //      //       //
//               ////////    //      //   //      //  //      //       //
//               //\\        //////////   //      //  //      //       //
//    ///////    //  \\      //      //    //    //   //      //       //
//        //     //   \\     //      //     // //     //      //       //
///////////      //    \\    //      //      //       //      //       //



////       /////////       //////////   //     //
// //      //     //       //           //     //
//  //     //     //       //           //     //
//   //    /////////       ////////     /////////
//   //    //     //             //     //     //
// //      //     //             //     //     //
///        //     //     /////////      //     //*/



#include<string>
#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;


enum colors { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, GRAY, LIGHTBLUE, LIGHTGREEN, TURQUOISE, LIGHTRED, PINK, YELLOW, WHITE };
const char met='°',nav='O',met1='°',nav1='O';

        
void gotoxy(int x, int y);
void setcolor(unsigned short int color, unsigned short int bg);
void VisualizzaCampo();
void ModSingola(string scelta);
void Info();
void SinglePlayer(string scelta);
void MultiPlayer(string selezione);
void ModMultipla(string selezione);
void VisualizzaCampo2();
void Intro();

// MAIN //
int main()
{
    string selezione;
    string modalita,scelta;
    int color;
    int bg;
    int x,y;
    
    gotoxy(x,y);
    setcolor(color, bg);
    Intro(); // Visualizzo la intro poi passo al menù principale
    do
    {
    	system("cls");
    	// MENU' PRINCIPALE DI GIOCO//
	setcolor(LIGHTRED,BLACK);
	gotoxy(25,3);
	cout<<"//////////          /////\n";
	gotoxy(25,4);
	cout<<"//                  //  ///\n";
	gotoxy(25,5);
	cout<<"//                  //    ///\n";
	gotoxy(25,6);
	cout<<"//                  //      //\n";
	gotoxy(25,7);
	cout<<"//    ///////       //      //\n";
	gotoxy(25,8);
	cout<<"//        //        //    //\n";
	gotoxy(25,9);
	cout<<"///////////   //    //////    //   \n";
       
	gotoxy(25,13);
	setcolor(GREEN,BLACK);
	cout<<"SCEGLI LA MODALITA' DI GIOCO";
	setcolor(YELLOW,BLACK);
	gotoxy(30,15);
	cout<<"1-- SinglePlayer";
	gotoxy(30,17);
	cout<<"2-- MultiPlayer";
	gotoxy(30,19);
	cout<<"3-- Informazioni";

	gotoxy(30,21);
	cout<<"0-- Esci";
	gotoxy(5,23);
	setcolor(LIGHTGRAY,BLACK);
	cout<<"SCELTA== ";
	setcolor(LIGHTRED,BLACK);
	cin>>modalita;
	setcolor(LIGHTGRAY,BLACK);
	
	if(modalita=="1")
	{
		SinglePlayer(scelta);
        }
        if(modalita=="2")
        {
                MultiPlayer(selezione);
        }
        if(modalita=="3")
        {
        	system("cls");
        	Info();
	}
    
    }while((modalita!="1")&&(modalita!="2")&&(modalita!="0"));
    
    exit(1);
	
}

// VISUALIZZA CAMPO //
void VisualizzaCampo() // carichiamo il campo di gioco dal file.txt
{
  char car;
  
  ifstream apri("board.txt", ios::in);
  while(!apri.eof())
  {
        apri >> car;
        if(car == '+')
        {
                cout << "\n";   
        }
        
        else if(car!='-')cout << car;
        
        if(car=='-') //se il carattere è "-" stampo 20 spazi
        {
                for(int i = 0;i < 19; i++)
                {
                        cout<<" ";
                }
                 
                if(car == '+') //se il carattere è "+" vado a capo
                {
                    	cout << "\n";   
                }
        }
  }
  
  return;
	
}

// MODALITA' SINGOLA //         
void ModSingola(string scelta)
{
	int h = 0 ,i = 10 ,j = 15 ,cont = 0 ,c ,pos = (rand()%19)+2 ,z = 2,x,v=50,time,velocita=0;
	char tasto;
	
	gotoxy(i,j); //posizionamento della navicella nella posizione iniziale
	cout<<nav;
	
	gotoxy(48,3);
	setcolor(YELLOW,BLACK);
	cout<<"TIMER";
	setcolor(LIGHTGRAY,BLACK);
	
	
	do
	{
		if(z==2)//quando un meteorite tocca terra z torna 2
		{
			if(i<11) // se la navicella è tra i primi 11 quadretti
			{
				c=(i) + (rand()%((i+3)-i+1));    //colonna a caso del meteorite               
               		}
               	
               		if(i>=11)
               		{
               			c=(i-3) + (rand()%(i-(i-3)+1)); //colonna a caso del meteorite
               		}
			
		}
		
		gotoxy(c,z);
               	setcolor(LIGHTGREEN,BLACK);
               	cout<<met;
               	setcolor(LIGHTGRAY,BLACK);
               
               	if(scelta=="4"){
               	Sleep(v);
               	cont++;
               	}
               
        	if(scelta=="1") //Modalità Facile
        	{
               		Sleep(40); //tempo di caduta del meteorite
               		cont++;     //Contatore del punteggio
               	}       
                          
               
               
               	if(scelta=="2")//Modalità Media
               	{
               		Sleep(33);
               		cont++;  
               	}
               
               	if(scelta=="3")// Modalità Difficile
               	{
               		Sleep(25);
               		cont++;  
               	}
               	
               	gotoxy(c,z);
               	cout<<" ";
               	z++;
               
               	if(z==16)
               	{         //Quando meteorite arriva in fondo scompare e si crea un altro meteorite
                	gotoxy(c,z);
                        cout<<" ";
                        z=2;
                         
                }
 
 	
 		if(kbhit()) // controllo se un tasto è premuto
 		{
 			x=getch();
 		
 			if(x==0xE0) // controllo se una freccetta direzionale
			{
            			x=getch();
            		
            			if(x==75)
            			{
            				gotoxy(i,j);
        				cout<<" ";
               				i--;//Sposta a sinistra
               				gotoxy(i,j);
               				cout<<nav;

               			}
               
               			if(x==77)
               			{
               				gotoxy(i,j);
               				cout<<" ";
               				i++; //Sposta a destra
               				gotoxy(i,j);
               				cout<<nav;
               		
               			}
               
               		}
               		
               		if(x==100)
			{
               			gotoxy(i,j);
               			cout<<" ";
               			i++;              //Sposta a destra
               			gotoxy(i,j);
               			cout<<nav;
               		}
               		
               		if(x==97)
               		{        
               			gotoxy(i,j);
               			cout<<" ";
               			i--;              //Sposta a sinistra
               			gotoxy(i,j);
               			cout<<nav;
               		}
 			
 		}
 		
 		if(i==21)
		{                       //Se becca il bordo hai perso
			h=1;
       		}
	
		if(i==1)
		{
			h=1;                   //Se becca il bordo hai perso
		}
        
   		if((i==c)&&(j==z))
   		{
        		h=1;		// se becca un meteorite hai perso
   		}
   	
   	
   	//timer//
	
		if(scelta=="1")// conteggio dei punti se la modalità è facile
		{
			if(cont%25>=1)
			{
              			gotoxy(50,5);
              			cout<<" ";
              			gotoxy(51,5);
		        	cout<<" ";
		        	gotoxy(52,5);
		        	cout<<" ";
		        	gotoxy(50,5);
		        	setcolor(LIGHTRED,BLACK);
		        	cout<<cont/25;
		        	setcolor(LIGHTGRAY,BLACK);
              		}
        	}

     	if(scelta=="2")// conteggio dei punti se la modalità è media
     	{
		if(cont%30>=1)
		{
              		gotoxy(50,5);
              		cout<<" ";
              		gotoxy(51,5);
              		cout<<" ";
              		gotoxy(52,5);
              		cout<<" ";
              		gotoxy(50,5);
              		setcolor(LIGHTRED,BLACK);
              		cout<<cont/30;
              		setcolor(LIGHTGRAY,BLACK);
              	}
        }

	if(scelta=="3")// conteggio dei punti se la modalità è difficile
	{
		if(cont%40>=1)
		{
               
              		gotoxy(50,5);
              		cout<<" ";
              		gotoxy(51,5);
              		cout<<" ";
              		gotoxy(52,5);
              		cout<<" ";
              		gotoxy(50,5);
              		setcolor(LIGHTRED,BLACK);
              		cout<<cont/40;
              		setcolor(LIGHTGRAY,BLACK);
              	}
        }
        
        if(scelta=="4")// conteggio dei punti se la modalità è survival
        {
        	time=1000/v;
        	if(cont%time>=1)
        	{
        		gotoxy(50,5);
              		cout<<" ";
              		gotoxy(51,5);
              		cout<<" ";
              		gotoxy(52,5);
              		cout<<" ";
              		gotoxy(50,5);
              		setcolor(LIGHTRED,BLACK);
              		cout<<cont/time;
        		
        		if((cont%100)==1)
        		{
                        	v--;
                               	velocita++;
              			gotoxy(50,7);
              			cout<<"velocita' = "<<velocita;
                        }
              	setcolor(LIGHTGRAY,BLACK);
        		
        	}
        	
        }
		
	}while(h==0);

	gotoxy(7,8);
	setcolor(LIGHTRED,BLACK);
	cout<<"hai perso";
	setcolor(LIGHTGRAY,BLACK);
	gotoxy(19,19);
	//stampa del risultato//
	gotoxy(37,15);
	setcolor(LIGHTBLUE,BLACK);
	if(scelta=="1")
	{
		cout<<"il tuo punteggio e'"<<cont/25<<" secondi";
	}

	if(scelta=="2")
	{
		cout<<"il tuo punteggio e'"<<cont/30<<" secondi";
	}

	if(scelta=="3")
	{
	cout<<"il tuo punteggio e'"<<cont/40<<" secondi";
	}

	if(scelta=="4")
	{
	cout<<"il tuo punteggio e'"<<cont/time<<" secondi";
	}

	setcolor(LIGHTGRAY,BLACK);
	// FINE STAMPA//
	
	return;
	
}


// INFORMAZIONI SUL GIOCO //
void Info()
{
	// piccolo manuale di gioco sulle regole basi //
	gotoxy(30,1);
     	setcolor(YELLOW,BLACK);
	cout<<"<<GRAVITY DASH>>";
	gotoxy(2,5);
	setcolor(LIGHTRED,BLACK);
	cout<<"COMANDI\n";
	setcolor(LIGHTGRAY,BLACK);
	cout<<"D = movimento a destra\n";
	cout<<"A = movimento a sinistra\n";
	cout<<"--> = movimento a destra\n";
	cout<<"<-- = movimento a sinistra\n";
	gotoxy(2,12);
     	setcolor(LIGHTRED,BLACK);
     	cout<<"SCOPO DEL GIOCO\n";
     	setcolor(LIGHTGRAY,BLACK);
     	cout<<"Non devi farti beccare dai meteoriti che scendono,\n";
     	cout<<"se vieni colpito perderai automaticamente e' il tuo\n";
     	cout<<"punteggio sara' il tempo che sei rimasto in vita.\n";
     	gotoxy(28,18);
     	setcolor(LIGHTRED,BLACK);
     	cout<<"CREDITI\n";
     	setcolor(LIGHTGRAY,BLACK);
     	gotoxy(24,20);
     	setcolor(LIGHTGREEN,BLACK);
     	cout<<"Civettini Marco\n";
     	setcolor(LIGHTGRAY,BLACK);
      	gotoxy(1,25);
     	setcolor(YELLOW,BLACK);
     	cout<<"PREMERE UN TASTO PER TORNARE AL MENU'";
     	gotoxy(1,24);
     	setcolor(BLACK,BLACK);
     	system("Pause");
     	setcolor(LIGHTGRAY,BLACK);
     	gotoxy(1,25);
     	system("cls");
     	main();
     	return;
	
}


// SCELTA DELLA MODALITA' SINGLEPLAYER //
void SinglePlayer(string scelta)
{
	int start;
     	char rew;

	do
	{
		start=5;
     		system("cls");
     
		do
		{
			gotoxy(35,3);
    			setcolor(YELLOW,BLACK);
    			cout<<"<<SINGLE PLAYER>>"; 
		    	gotoxy(16,8); 
		    	setcolor(LIGHTBLUE,BLACK);
		    	cout<<"Inserisci il numero della difficolta' di gioco\n\n";
		    	gotoxy(18,10);
		    	setcolor(LIGHTGREEN,BLACK);
		    	cout<<"1 --> Facile\n\n";
		    	gotoxy(18,12);
		    	cout<<"2 --> Normale\n\n";
		    	gotoxy(18,14);
		    	cout<<"3 --> Difficile\n\n";
		    	gotoxy(18,16);
		    	cout<<"4 --> Survival\n\n";
		    	gotoxy(18,18);
		    	cout<<"0 --> Torna alla home\n\n";
		    	setcolor(LIGHTGRAY,BLACK);
		    	gotoxy(5,23);
		    	cout<<"SCELTA = ";
		    	setcolor(LIGHTRED,BLACK);
		    	cin>>scelta;
		    	setcolor(LIGHTGRAY,BLACK);
		    	system("cls");
		    	
		    	if(scelta=="0")
		    	{
                  		main(); ;
                  	}
                  	
                  	system("cls");
    		
		}while((scelta!="1")&&(scelta!="2")&&(scelta!="3")&&(scelta!="4")&&(scelta!="0"));

		////////CONTO ALLA ROVESCIA////////
		VisualizzaCampo();
		setcolor(LIGHTGREEN,BLACK);
		gotoxy(6,8);
    		cout<<"START TRA";
		setcolor(LIGHTRED,BLACK);
		gotoxy(42,4);
		cout<<"Comandi per MANCINI";
		setcolor(YELLOW,BLACK);
		gotoxy(42,6);
		cout<<"D = Muovi a destra";
		gotoxy(42,8);
		cout<<"A = Muovi a sinistra";
		gotoxy(42,11);
		setcolor(LIGHTRED,BLACK);
		cout<<"Comandi per DESTRORSI";
		setcolor(YELLOW,BLACK);
		gotoxy(42,13);
		cout<<"---> = Muovi a destra";
		gotoxy(42,15);
		cout<<"<--- = Muovi a sinistra";
		setcolor(LIGHTGRAY,BLACK);
	
		do
		{
			gotoxy(16,8);
    			setcolor(YELLOW,BLACK);
    			cout<<start;
    			Sleep(1000);
    			start--;
    		}while(start!=0);
	/////////////////////////

    		setcolor(LIGHTGRAY,BLACK);
    		system("cls");
    		srand(time(NULL));   
    		//FUNZIONI//
    		VisualizzaCampo();
    		ModSingola(scelta);
    		//       //
    		gotoxy(1,23);
    		setcolor(LIGHTGREEN,BLACK);
		cout<<"vuoi riprovare?(s/n)";
     		setcolor(LIGHTGRAY,BLACK);
     		cin>>rew;
     		system("cls");
		
	}while((rew=='s')||(rew=='S'));
	
	return;
	
}
     
 
 
 
 
 
 
 
 
 void ModMultipla(string selezione)
{
	int h = 0 ,i = 11 ,j = 15 ,r=51,k=15,cont = 0 ,c,c1,pos = (rand()%19)+2 ,z = 2,x,v=40,time,velocita=0;
	char tasto;

                                  //Stampa la prima volta la navicella        
     	gotoxy(i,j);
     	cout<<nav;
     	gotoxy(r,k);
     	cout<<nav1;

	gotoxy(28,4);
	setcolor(YELLOW,BLACK);
	cout<<"TIMER";
	setcolor(LIGHTBLUE,BLACK);
	gotoxy(7,19);
	cout<<"Giocatore 1";
	setcolor(YELLOW,BLACK);
	gotoxy(47,19);
	cout<<"Giocatore 2";
	setcolor(LIGHTGRAY,BLACK);
	
	do
	{
		if(z==2)
		{
			if(i<11)
			{
				c=(i) + (rand()%((i+3)-i+1));    //colonna a caso del meteorite               
               		}  
               
               		if(i>=11)
               		{
         			c=(i-3) + (rand()%(i-(i-3)+1)); //colonna a caso del meteorite
               		}
               
	               if(r<31)
	               {
	               		c1=(r) + (rand()%((r+3)-r+1));    //colonna a caso del meteorite               
	               }
	               
	               if(r>=31)
	               {
	               c1=(r-3) + (rand()%(r-(r-3)+1)); //colonna a caso del meteorite
	               }
            
		}
	               
	        gotoxy(c,z);
	        setcolor(LIGHTGREEN,BLACK);
	        cout<<met;
	        setcolor(LIGHTGRAY,BLACK);
	        //STAMPO METEORITE 2//
	        gotoxy(c1,z);
	        setcolor(LIGHTGREEN,BLACK);
	        cout<<met1;
	        setcolor(LIGHTGRAY,BLACK);
	        if(selezione=="1")
	        {
	        	Sleep(40); //tempo di caduta del meteorite
	               	cont++;     //Contatore del punteggio
	        }       
	                          
	        if(selezione=="2")
	        {
	               Sleep(33);
	               cont++;  
	        }
	               
	        if(selezione=="3")
	        {
	               Sleep(25);
	               cont++;  
	        }
	               
	        if(selezione=="4")
	        {
	               Sleep(v);
	               cont++;  
	        }
	                             
	               
	               
	        gotoxy(c,z);
	        cout<<" ";
	        gotoxy(c1,z);
	        cout<<" ";
	        z++;
	               
	        if(z==16)
	        {         //Quando meteorite arriva in fondo scompare e si crea un altro meteorite
	        	gotoxy(c,z);
	                cout<<" ";
	                gotoxy(c1,z);
	                cout<<" ";
	                z=2;
	                         
	        }
	        
	        if(kbhit())
	        {
	        	x=getch();
	        	
	        	if(x==0xE0)
	        	{
	            		x=getch();
	            
	            
	              		if(x==75)
	              		{        
	               			gotoxy(r,k);
	               			cout<<" ";
	               			r--;              //Sposta a sinistra
	               			gotoxy(r,k);
	               			cout<<nav;
	               		}
	               
	               		if(x==77)
	               		{
	               			gotoxy(r,k);
	               			cout<<" ";
	               			r++;              //Sposta a destra
	               			gotoxy(r,k);
	               			cout<<nav;
	               		}
	               
	               
			}
	
			if(x==100)
			{
				gotoxy(i,j);
	               		cout<<" ";
	               		i++;              //Sposta a destra
	               		gotoxy(i,j);
	               		cout<<nav;
	        	}
	        
		        if(x==97)
	        	{        
	               	gotoxy(i,j);
	               	cout<<" ";
	               	i--;              //Sposta a sinistra
	               	gotoxy(i,j);
	               	cout<<nav;
	        	}
	        	
		}
		
		if(i==21)
		{
			h=1;
			gotoxy(19,21);
			cout<<"il";
			setcolor(LIGHTGREEN,BLACK);
			cout<<" giocatore 2 ";
			setcolor(LIGHTGRAY,BLACK);
			cout<<"ha vinto";
			gotoxy(7,9);
			setcolor(LIGHTRED,BLACK);
			cout<<"hai Perso";
			gotoxy(47,9);
			setcolor(LIGHTGREEN,BLACK);
			cout<<"hai Vinto";
			setcolor(LIGHTGRAY,BLACK);
	        }
	
		if(i==1)
		{
		h=1;
		gotoxy(19,21);
		cout<<"il";
		setcolor(LIGHTGREEN,BLACK);
		cout<<" giocatore 2 ";
		setcolor(LIGHTGRAY,BLACK);
		cout<<"ha vinto";
		gotoxy(7,9);
		setcolor(LIGHTRED,BLACK);
		cout<<"hai Perso";
		gotoxy(47,9);
		setcolor(LIGHTGREEN,BLACK);
		cout<<"hai Vinto";
		setcolor(LIGHTGRAY,BLACK);                            //Se becca il bordo hai perso
	        }
	        
		if((i==c)&&(j==z))
		{
			h=1;
			gotoxy(19,21);
			cout<<"il";
			setcolor(LIGHTGREEN,BLACK);
			cout<<" giocatore 2 ";
			setcolor(LIGHTGRAY,BLACK);
			cout<<"ha vinto";
			gotoxy(7,9);
			setcolor(LIGHTRED,BLACK);
			cout<<"hai Perso";
			gotoxy(47,9);
			setcolor(LIGHTGREEN,BLACK);
			cout<<"hai Vinto";
			setcolor(LIGHTGRAY,BLACK);
		}
	
	//CONTROLLI SECONDA NAVICELLA//
		if(r==61)
		{                       //Se becca il bordo hai perso
			h=1;
			gotoxy(19,21);
			cout<<"il";
			setcolor(LIGHTGREEN,BLACK);
			cout<<" giocatore 1 ";
			setcolor(LIGHTGRAY,BLACK);
			cout<<"ha vinto";
			gotoxy(47,9);
			setcolor(LIGHTRED,BLACK);
			cout<<"hai Perso";
			gotoxy(7,9);
			setcolor(LIGHTGREEN,BLACK);
			cout<<"hai Vinto";
			setcolor(LIGHTGRAY,BLACK);
	        }
	
		if(r==41)
		{
			h=1;
			gotoxy(19,21);
			cout<<"il";
			setcolor(LIGHTGREEN,BLACK);
			cout<<" giocatore 1 ";
			setcolor(LIGHTGRAY,BLACK);
			cout<<"ha vinto";
			gotoxy(47,9);
			setcolor(LIGHTRED,BLACK);
			cout<<"hai Perso";
			gotoxy(7,9);
			setcolor(LIGHTGREEN,BLACK);
			cout<<"hai Vinto";
			setcolor(LIGHTGRAY,BLACK);                           //Se becca il bordo hai perso
	        }
	        
		if((r==c1)&&(k==z))
		{
	
	                h=1;          
			gotoxy(19,21);
			cout<<"il";
			setcolor(LIGHTGREEN,BLACK);
			cout<<" giocatore 1 ";
			setcolor(LIGHTGRAY,BLACK);
			cout<<"ha vinto";
			gotoxy(47,9);
			setcolor(LIGHTRED,BLACK);
			cout<<"hai Perso";
			gotoxy(7,9);
			setcolor(LIGHTGREEN,BLACK);
			cout<<"hai Vinto";
			setcolor(LIGHTGRAY,BLACK);
		}


//TIMER//
		if(selezione=="1")
		{
			if(cont%25>=1)
			{
	              		gotoxy(30,9);
	              		cout<<" ";
	              		gotoxy(31,9);
	              		cout<<" ";
	              		gotoxy(32,9);
	              		cout<<" ";
	              		gotoxy(30,9);
	              		setcolor(LIGHTRED,BLACK);
	              		cout<<cont/25;
	              		setcolor(LIGHTGRAY,BLACK);
	              	}
	        }
	
		if(selezione=="2")
		{
			if(cont%30>=1)
			{
	              		gotoxy(30,9);
			        cout<<" ";
			        gotoxy(31,9);
			        cout<<" ";
			        gotoxy(32,9);
			        cout<<" ";
			        gotoxy(30,9);
			        setcolor(LIGHTRED,BLACK);
			        cout<<cont/30;
			        setcolor(LIGHTGRAY,BLACK);
	              }
	        }
	        
	        if(selezione=="3")
	        {
	        	if(cont%40>=1)
	        	{
	               
	              		gotoxy(30,9);
	              		cout<<" ";
	              		gotoxy(31,9);
	              		cout<<" ";
	              		gotoxy(32,9);
	              		cout<<" ";
	              		gotoxy(30,9);
	              		setcolor(LIGHTRED,BLACK);
	              		cout<<cont/40;
	              		setcolor(LIGHTGRAY,BLACK);
	        		
	        	}
	       	
	        	
	        }
	
		if(selezione=="4")
		{
			time=1000/v;
			if(cont%time>=1)
			{
	              		gotoxy(30,5);
	              		cout<<" ";
	              		gotoxy(31,5);
	              		cout<<" ";
	              		gotoxy(32,5);
	              		cout<<" ";
	              		gotoxy(30,5);
	              		setcolor(LIGHTRED,BLACK);
	              		cout<<cont/time;
	              	
	              		if((cont%100)==1)
	              		{
	                        	v--;
	                        	velocita++;
	              			gotoxy(26,9);
	              			setcolor(YELLOW,BLACK);
	              			cout<<"VELOCITA'";
	              			gotoxy(30,10);
	              			setcolor(LIGHTRED,BLACK);
	              			cout<<velocita;
	                	}
	              
	              		setcolor(LIGHTGRAY,BLACK);
				
			}
			
		}
		
	}while(h==0);
	
	return;
	
}    
     




     
void MultiPlayer(string selezione)
{
     int start;
     char rew;

do{
     start=5;
     system("cls");
     
do{
     
    gotoxy(35,3);
    setcolor(YELLOW,BLACK);
    cout<<"<<MULTI PLAYER>>"; 
    gotoxy(16,7); 
    setcolor(LIGHTBLUE,BLACK);
    cout<<"Inserisci il numero della difficolta' di gioco\n\n";
    gotoxy(18,10);
    setcolor(LIGHTGREEN,BLACK);
    cout<<"1 --> Facile\n\n";
    gotoxy(18,12);
    cout<<"2 --> Normale\n\n";
    gotoxy(18,14);
    cout<<"3 --> Difficile\n\n";
    gotoxy(18,16);
    cout<<"4 --> Survival\n\n";
    gotoxy(18,18);
    cout<<"0 --> Torna alla home\n\n";
    setcolor(LIGHTGRAY,BLACK);
    gotoxy(5,23);
    cout<<"SCELTA = ";
        setcolor(LIGHTRED,BLACK);
    cin>>selezione;
    setcolor(LIGHTGRAY,BLACK);
    system("cls");
    if(selezione=="0"){
                  main(); ;
                  }

    system("cls");
    }while((selezione!="1")&&(selezione!="2")&&(selezione!="3")&&(selezione!="4")&&(selezione!="0"));
////////CONTO ALLA ROVESCIA////////
VisualizzaCampo2();
setcolor(LIGHTGREEN,BLACK);
   gotoxy(26,7);
    cout<<"START TRA";
setcolor(YELLOW,BLACK);    
    gotoxy(3,19);
    cout<<"D = Muoviti a Destra";
setcolor(LIGHTRED,BLACK);
    gotoxy(3,21);
    cout<<"A = Muoviti a Sinistra";
setcolor(YELLOW,BLACK);    
    gotoxy(43,19);
    cout<<"---> = Muoviti a Destra";
setcolor(LIGHTRED,BLACK);
    gotoxy(43,21);
    cout<<"<--- = Muoviti a Sinistra";
    do{
    
    Sleep(1000);
    gotoxy(30,8);
    setcolor(YELLOW,BLACK);
    cout<<start;
    start--;
    }while(start!=0);
/////////////////////////

    setcolor(LIGHTGRAY,BLACK);
    system("cls");
    srand(time(NULL));   
    //FUNZIONI//
    VisualizzaCampo2();
    ModMultipla(selezione);
    //       //
    gotoxy(1,24);
    setcolor(LIGHTGREEN,BLACK);
     cout<<"vuoi riprovare?(s/n)";
     setcolor(LIGHTGRAY,BLACK);
     cin>>rew;
     system("cls");
   }while((rew=='s')||(rew=='S'));
    
 
return;     
     }



void VisualizzaCampo2() // carichiamo il campo di gioco dal file.txt
{
  char car;
       
  ifstream apri("Board2.txt", ios::in);
  while(!apri.eof()){
         apri >> car;
         if(car == '+'){
                    cout << "\n";   
         }
         else if(car!='-')cout << car;
        if(car=='-')
        {
                    for(int i = 0;i < 19; i++)
                    {
                            cout<<" ";
                    }
                    if(car == '+')
                    {
                    cout << "\n";   
                    }
        }

        }
return;

}




void Intro()
{
     setcolor(YELLOW,BLACK);
     gotoxy(2,2);
     cout<<"//////////      /////////   //////////   //      //  //  //////////  //      //";
     gotoxy(2,3);
     cout<<"//              //     //   //      //   //      //          //        //  //  ";
     gotoxy(2,4);
     cout<<"//              ////////    //      //   //      //  //      //          //    ";
     gotoxy(2,5);
     cout<<"//              // //       //////////   //      //  //      //          //    ";
     gotoxy(2,6);
     cout<<"//    ///////   //  //      //      //    //    //   //      //          //    ";
     gotoxy(2,7);
     cout<<"//        //    //   //     //      //     // //     //      //          //    ";
     gotoxy(2,8);
     cout<<"///////////     //    //    //      //      //       //      //          //    ";
     setcolor(LIGHTRED,BLACK);
     gotoxy(13,12);
     cout<<"////       /////////       //////////   //     //";
     gotoxy(13,13);
     cout<<"// //      //     //       //           //     //";
     gotoxy(13,14);
     cout<<"//  //     //     //       //           //     //";
     gotoxy(13,15);
     cout<<"//   //    /////////       ////////     /////////";
     gotoxy(13,16);
     cout<<"//   //    //     //             //     //     //";
     gotoxy(13,17);
     cout<<"// //      //     //             //     //     //";
     gotoxy(13,18);
     cout<<"///        //     //     /////////      //     //";

     gotoxy(30,22);
     setcolor(LIGHTGREEN,BLACK);
     cout<<"By Civettini Marco";
     Sleep(3000);

     
     return;
     }
     
     
 //CHIAMO LE FUNZIONI PER IL GOTO XY e SYSTEMCOLOR    
void gotoxy(int x, int y)
{
COORD pos = { x-1, y-1 };
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setcolor(unsigned short int color, unsigned short int bg)
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((bg*16)+(color)));
}
