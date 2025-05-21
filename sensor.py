import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.const import CONF_NAME, CONF_UPDATE_INTERVAL
from esphome.components import sensor, microphone
import esphome.components.polling_component as polling_component

DEPENDENCIES = ['microphone']

CONF_ECHO_MICROPHONE = 'echo_microphone'

PLATFORM_SCHEMA = sensor.PLATFORM_SCHEMA.extend({
    cv.Required(CONF_ECHO_MICROPHONE): cv.use_id(microphone.I2SAudioComponent),
}).extend(polling_component.POLLING_COMPONENT_SCHEMA.schema)

async def to_code(config):
    mic = await cg.get_variable(config[CONF_ECHO_MICROPHONE])
    noise = cg.new_Pvariable(config[CONF_NAME], mic)
    await polling_component.register_polling_component(noise, config)
    await sensor.register_sensor(noise, config)
