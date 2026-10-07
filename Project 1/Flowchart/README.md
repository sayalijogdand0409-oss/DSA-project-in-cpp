## Project Flowchart

```mermaid
flowchart TD
    A([START]) --> B[Initialize System]
    B --> C[Detect Traffic Density]
    C --> D{Emergency Vehicle Detected?}

    D -- Yes --> E[Identify Emergency Vehicle Lane]
    E --> F[Turn Emergency Lane GREEN]
    F --> G[Turn Other Lanes RED]
    G --> H[Emergency Vehicle Passes]
    H --> I[Return to Normal Mode]

    D -- No --> J[Calculate Traffic Density]
    J --> K{Compare Lane Density}
    K --> L[Adjust Signal Timing]
    L --> M[Continue Traffic Monitoring]

    I --> C
    M --> C
