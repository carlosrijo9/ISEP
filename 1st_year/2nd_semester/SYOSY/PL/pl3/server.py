# server.py

import aiocoap.resource as resource
import aiocoap
import threading
import logging
import asyncio
import time

class AlarmResource(resource.ObservableResource):
    """Example resource that can be observed. The `notify` method keeps
    scheduling itself, and calles `update_state` to trigger sending
    notifications."""
    
    def __init__(self):
        super().__init__()

        self.handle = None
        self.status = "OFF"
        self.notify_observers = False

    def notify(self):
        if (self.notify_observers):
            print('Notifying observers')
            self.updated_state()
            self.notify_observers = False
        self.reschedule()

    def reschedule(self):
        self.handle = asyncio.get_event_loop().call_later(5, self.notify)

    def update_observation_count(self, count):
        if count and self.handle is None:
            print("Starting the clock")
            self.reschedule()
        if count == 0 and self.handle:
            print("Stopping the clock")
            self.handle.cancel()
            self.handle = None

    async def render_get(self, request):
        print('Return alarm state: %s' % self.status)
        payload = b'%s' % self.status.encode('ascii')

        return aiocoap.Message(payload=payload)
    
     # Handles PUT request
    async def render_put(self, request):
        self.status = request.payload.decode('ascii')
        print('Update alarm state: %s' % self.status)
        self.notify_observers = True

        return aiocoap.Message(code=aiocoap.CHANGED, payload=b'%s' % self.status.encode('ascii'))

    
#logging.basicConfig(level=logging.INFO)
#logging.getLogger("coap-server").setLevel(logging.DEBUG)

async def main():
    # Resource tree creation
    root = resource.Site()
    alarmResource = AlarmResource()
    root.add_resource(['alarm'], AlarmResource())

    await aiocoap.Context.create_server_context(root)
    await asyncio.get_running_loop().create_future()

if __name__ == "__main__":
    asyncio.run(main())