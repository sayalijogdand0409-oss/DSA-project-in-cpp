## Project Test Cases

| Test Case | Input / Condition | Expected Result | Status |
|---|---|---|---|
| TC01 | No vehicles detected | Traffic signals operate in normal mode | PASS |
| TC02 | Low traffic density | Short green signal duration | PASS |
| TC03 | Medium traffic density | Normal green signal duration | PASS |
| TC04 | High traffic density | Longer green signal duration | PASS |
| TC05 | Emergency vehicle detected | Emergency vehicle lane turns GREEN | PASS |
| TC06 | Emergency vehicle detected | Other lanes turn RED | PASS |
| TC07 | Emergency vehicle passes | System returns to normal traffic mode | PASS |
| TC08 | Multiple lanes with different traffic density | Lane with higher density gets priority | PASS |
| TC09 | Sensor detects changing traffic | Signal timing adjusts accordingly | PASS |
| TC10 | System switched OFF | All system operations stop | PASS |
