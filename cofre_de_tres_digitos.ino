/* cofre de três dígitos.21º projeto.linguagem utilizada c++
  criado por: Leonardo de Oliveira Prado
  Instagram: arduino2.0tecnologico

  Data de inicio do projeto 07/09/2023
  Data de término do projeto 07/09/2023  

*/
String senha="3132"; //senhas e sua sequência (pode motificar somente nesta linha + ou - numeros )
String digitado;
int tentativa = 0;

#define bota1 2
#define bota2 3
#define bota3 4

#define vermelho 5
#define verde 6

#define bazzer 7

void setup()
{
pinMode(bota1,INPUT_PULLUP);
pinMode(bota2,INPUT_PULLUP);
pinMode(bota3,INPUT_PULLUP);
pinMode(vermelho, OUTPUT);
pinMode(verde, OUTPUT);
pinMode(bazzer, OUTPUT);

//Serial.begin(9600);
}

void loop()
{
//*********************************************faz o barulho do botão apertado**************************************************************************************
 if(digitalRead(bota1)==LOW){
  tone(bazzer, 523, 100); // piezo buzzer
  delay(100);
 }else{
  noTone(bazzer);
 }
  if(digitalRead(bota2)==LOW){
  tone(bazzer, 523, 100); // piezo buzzer
  delay(100);
  }else{
  noTone(bazzer);
 }
  if(digitalRead(bota3)==LOW){
  tone(bazzer, 523, 100); // piezo buzzer
  delay(100);
  }else{
  noTone(bazzer);
 }
//********************************************adiciona os numeros da senha*************************************************************************************
  if (digitalRead(bota1)==0) {
  digitado=digitado +"1";
  delay(300);
  tentativa++;
  }
  if (digitalRead(bota2)==0){
    digitado=digitado +"2";
    delay(300);
    tentativa++;
  }
  if (digitalRead(bota3 )==0){
    digitado = digitado +"3";
    delay(300);
    tentativa++;
  }
   
//*****************************************verifica se a senha está correta ou não****************************************************************************************
  if(digitado == senha) {
   digitalWrite(verde,HIGH);
   tone(bazzer, 523, 2000); // piezo buzzer
   delay(4000);
   noTone(bazzer);
   digitado="";
  }else{
    digitalWrite(verde,LOW);

  if (tentativa >4){
    digitado="";
    digitalWrite(vermelho, HIGH);
    tone(bazzer, 294, 2000); // piezo buzzer
     delay(2000);
     noTone(bazzer);
    tentativa=0;
  }else{
    digitalWrite(vermelho, LOW);
  }
  //Serial.println(digitado);
  delay(10);
  }
}
