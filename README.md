# Guardgram
Controlling ESP32-CAM via Telegram bot ( take and send photos )

### Revision history

* v0.0.1-07042021
  - Support take photos and send it via telegram bot
  - Support change lamp status via telegram bot
  - Config Guardgram manually only (WiFi Credentials, Telegram Bot Token, and Telegram user ID)

### How to get Telegram Bot Token
To take you one Telegram Bot Token you need to create a Telegram Bot. Open Telegram App, then Search for @botfather, or open t.me/botfather.
When botfather opened, click start button,  then write or choose /newbot and follow the instructions to create your bot, you will give it a name and username. If your bot is successfully created, you’ll receive a message with a link to access the bot and the bot token, like this:

```
Done! Congratulations on your new bot. You will find it at t.me/xxxxxxxx. You can now add a description, about section and profile picture for your bot, see /help for a list of commands. By the way, when you've finished creating your cool bot, ping our Bot Support if you want a better username for it. Just make sure the bot is fully operational before you do this.

Use this token to access the HTTP API:
XXXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
Keep your token secure and store it safely, it can be used by anyone to control your bot.

For a description of the Bot API, see this page: https://core.telegram.org/bots/api
```
Your bot token is: XXXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

### How to get User ID
Anyone has your bot username can control your Guardgram, to make sure that your Guardgram authorized you only to control it, you need to put your Telegram User ID to Guardgram configuration.
To get it, open Telegram app, search for @IDBot or open this link t.me/myidbot. type /getid. You will get a reply back with your user ID. 

### Guardgram configuration 
* In v0.0.1-07042021, you need to put manually: Telegram bot token and Telegram User ID in guardgram_telegrambot.h , and WiFi Credentials in guardgram_wifi.h

### Copyright CC 2020 Walid Amriou

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.

__You are free to:__
  * Share — copy and redistribute the material in any medium or format
  * Adapt — remix, transform, and build upon the material
The licensor cannot revoke these freedoms as long as you follow the license terms.  

__Under the following terms:__
  * Attribution — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
  * NonCommercial — You may not use the material for commercial purposes.
  * ShareAlike — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.
  * No additional restrictions — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.


the software or Code or Scripts or any files in this source is provided "as is" and the author disclaims all warranties with regard to this files including all implied warranties of merchantability and fitness. in no event shall the author be liable for any special, direct, indirect, or consequential damages or any damages whatsoever resulting from loss of use, data or profits, whether in an action of contract, negligence or other tortious action, arising out of or in connection with the use or performance of this software or code or scripts or any files in this source.
