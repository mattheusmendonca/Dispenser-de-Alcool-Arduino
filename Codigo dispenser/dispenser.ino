#define echo 4
#define trig 5

unsigned long tempo;
double distancia;

int IN1 = 2;
int IN2 = 3;

void setup(){
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(echo, INPUT); //Echo do sensor ultrassônico
 pinMode(trig, OUTPUT); //Trigger do sensor ultrassônico
 Serial.begin(9600); 
}

void loop(){
  ultra();

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);

  if(distancia <= 12){
    //Gira o Motor no sentido horario
    Serial.println("Ligado");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //teste = 1;
    delay(500);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    delay(5000);
  }
  delay(10);
}

void ultra(){
    digitalWrite(trig, LOW);
    delay(10);

    digitalWrite(trig, HIGH);// Define o trigger como high
    delayMicroseconds(10);
    digitalWrite(trig, LOW);// Define o trigger como low
    tempo= pulseIn(echo, HIGH);// Calcula o tempo para recebero sinal no Echo
    distancia = tempo/58;//Corrige a distância
    Serial.println(distancia);
    delay(500);
}