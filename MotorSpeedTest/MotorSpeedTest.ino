// Motor A connections
int enA = 5;
int in1 = 3;
int in2 = 2;


void setup() {
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}

void loop() {
	speedControl();
	delay(1000);
}


// This function lets you control speed of the motors
void speedControl() {
	// Turn on motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	
	// Accelerate from zero to maximum speed
	for (int i = 0; i < 256; i++) {
		analogWrite(enA, i);
		delay(20);
	}
	
	// Decelerate from maximum speed to zero
	for (int i = 255; i >= 0; --i) {
		analogWrite(enA, i);
		delay(20);
	}
	
	// Now turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
}