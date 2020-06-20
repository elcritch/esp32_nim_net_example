
var portTICK_PERIOD_MS* {.importc: "portTICK_PERIOD_MS", header: "<freertos/FreeRTOS.h>".}: cint

proc delay*( milsecs: cint ) {.cdecl, importc: "delay".}
proc esp_restart*() {.cdecl, importc: "esp_restart".}

proc vTaskDelete*( handle: any )
  {.cdecl, importc: "vTaskDelete", header: "<freertos/FreeRTOS.h>".}
