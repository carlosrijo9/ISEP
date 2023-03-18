# client_observe.py

import logging
import asyncio

from aiocoap import *

logging.basicConfig(level=logging.INFO)

def observe_callback(response):
        print("Alarm status: %s" % (response.payload.decode('ascii')))
        if response.code.is_successful():
            print("Alarm status: %s" % (response.payload.decode('ascii')))
        else:
            print('Error code %s' % response.code)

async def main():
    context = await Context.create_client_context()

    request = Message(code=GET)
    request.set_request_uri('coap://localhost/alarm')
    request.opt.observe = 1
    observation_is_over = asyncio.Future()

    try:
        context_request = context.request(request)
        context_request.observation.register_callback(observe_callback)
        response = await context_request.response
        exit_reason = await observation_is_over
        print('Observation is over: %r' % exit_reason)
    finally:
        if not context_request.response.done():
            context_request.response.cancel()
        if not context_request.observation.cancelled:
            context_request.observation.cancel()

if __name__ == "__main__":
    asyncio.run(main())