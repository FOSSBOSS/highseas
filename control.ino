int C = 0;  // variable for noise compensation

int computeAmbientNoise() {
    // take N samples to adjust for ambient noise
    long sum1 = 0, sum2 = 0;
    const int nSamples = 10;  
    for (int i = 0; i < nSamples; i++) {
        sum1 += analogRead(A0);
        sum2 += analogRead(A1);
        delay(10);  // delay to inhibit noise between readings
    }
    return (sum1 / nSamples + sum2 / nSamples) / 2;  
}

void setup() {
    Serial.begin(19200); 
    C = computeAmbientNoise();  
    Serial.print("Calibrated Ambient Noise Level: ");
    Serial.println(C);
}

void loop() {
    int A = analogRead(A0);
    int B = analogRead(A1);

    int AA = max(0, A - C);  
    int BB = max(0, B - C);

    Serial.print("A:");
    Serial.print(AA);
    Serial.print(", B:");
    Serial.println(BB);
    Serial.flush();

    delay(500); 
}
