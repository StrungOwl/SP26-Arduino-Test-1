#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();                 // ensure I2C started
  Wire.setClock(100000);        // 100kHz is safest for long jumpers

  delay(200);                   // small power-up settle
  uint8_t addr = 0x68;          // or 0x69 if your scanner showed that
  if (!mpu.begin(addr)) {
    Serial.println("Failed to find MPU6050 chip.");
    while (1) { delay(10); }
  }
  Serial.println("MPU6050 found!");
  mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Serial.print("Accel X: "); Serial.print(a.acceleration.x);
  Serial.print("  Y: ");     Serial.print(a.acceleration.y);
  Serial.print("  Z: ");     Serial.println(a.acceleration.z);
  delay(100);
}

