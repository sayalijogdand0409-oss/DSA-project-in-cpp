## Algorithm

### Smart Traffic & Emergency Priority Logic

**01 ──> START**  
Initialize the microcontroller, sensors, and traffic lights.

**02 ──> DETECT TRAFFIC**  
Read the number of vehicles on each road using sensors.

**03 ──> CALCULATE DENSITY**  
Determine the traffic density of each lane.

**04 ──> CHECK EMERGENCY**  
Check whether an emergency vehicle is approaching.

**05 ──> EMERGENCY DETECTED?**

**YES ➜**  
Identify the emergency vehicle's lane  
↓  
Turn that lane GREEN  
↓  
Turn other lanes RED  
↓  
Allow the emergency vehicle to pass  
↓  
Return to normal operation

**NO ➜**  
Compare traffic density  
↓  
Give longer GREEN time to the lane with higher traffic  
↓  
Adjust signal timing for other lanes  
↓  
Continue monitoring

**06 ──> REPEAT**  
Continuously monitor traffic and emergency vehicles.

**07 ──> STOP**  
Stop the system when the power is switched OFF.
