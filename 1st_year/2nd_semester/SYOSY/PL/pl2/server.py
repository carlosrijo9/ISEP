# server.py
import asyncio
import aiocoap.resource as resource
import aiocoap

class AlarmResource(resource.Resource):


# This resource supports the PUT method. 
# PUT: Update state of alarm

    def __init__(self):
        super().__init__()
        self.state = "OFF"
        self.content = b"Hello, world!"

    async def render_put(self, request):
        self.state = request.payload
        print('Update alarm state: %s' % self.state)
        await asyncio.sleep(5)
        return aiocoap.Message(code=aiocoap.CHANGED, payload=self.state)

    async def render_get(self, request):
        print('aa')
        return aiocoap.Message(payload=self.content)

# create a main() method to initialise the server and add the alarm resources to it.
import asyncio
async def main():
    # Resource tree creation
    root = resource.Site()
    root.add_resource(['alarm'], AlarmResource())
    await aiocoap.Context.create_server_context(root)
    await asyncio.get_running_loop().create_future()

if __name__ == "__main__":
    asyncio.run(main())
