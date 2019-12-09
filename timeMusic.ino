float mic = A1;
float R = 11;
float G = 10;
float B = 3;
void setup() {
  Serial.begin (9600);
  // put your setup code here, to run once:
  pinMode(mic,INPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  //seleziono il microfono come input ed i led come output
}

void loop() {
  
  // put your main code here, to run repeatedly:
  int musicWave = analogRead(mic);//prendo in input la frequenza data dal microfono
  //in base alla frequenza accendo i led ad un certo colore
  if(musicWave>=875)
    {
      colorRGB(255,0,0);
    }
    if(musicWave>=575 && musicWave<875)
    {
      colorRGB(0,255,0);
    }
    if(musicWave>=275 && musicWave<575)
    {
      colorRGB(0,0,255);
    }
    if(musicWave<275)
    {
      colorRGB(255,255,0);
      digitalWrite(R,LOW);
      digitalWrite(G,LOW);
      digitalWrite(B,LOW);
    }
}
//dato che il circuito prende un singolo valore alla volta 
//scrivo questa funzione per facilitarmi l'output
void colorRGB(float r,float g,float b)
{
  digitalWrite(R,r);
  digitalWrite(G,g);
  digitalWrite(B,b);
  
}
