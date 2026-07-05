AFKMud Intermud-3 Driver Code For DikuMUDs
==========================================

Original version written by Fatal Dimensions, see the LICENSE file.
Ported to Smaug 1.4a by Samson of Alsherok
Consolidated for cross-codebase compatibility by Samson of Alsherok
Permission for me to redistribute was granted by Fatal Dimensions.

Driver Version 2.40c

Need a router too?
You can find one here: https://github.com/Arthmoor/I3-Router

What this code does
===================

A word of caution - this isn't intended for beginning coders.
You have been warned.

This code gives your mud the ability to connect to the Intermud-3 chat
network, which is more or less the same idea as the IMC2 network some
of you may already be familiar with or members of. This originally
started off as simply a Smaug port of the code I began from, but once
I had done that I realized this would be of use to far more than just
Smaug. So once I had the Smaug code working to my satisfaction and
cleaned up to be less cluttery than what I started with, I set about
making it compile on several codebases as a standard package.
The result is what you see here. This code is a vast improvement over
the Fatal Dimensions code, as it now properly handles TCP exceptions
and socket read/write errors. It also now supports color throughout.
It has also been condensed down from the original 14 files to this
set of 3 for ease of maintenance.

This code should present no obstacles to use alongside a mud with an IMC2
network connection.

Despite what a number of people have said, Intermud-3 is built upon a
more stable and expandable protocol. And if your on a host where you
can't bind more than one port per process, IMC2 ( at least with older versions )
is out of the question since it requires you to bind an extra port for
its incoming traffic. I3 is also much cleaner, and its specs are
publically documented. I3 also does not require that you apply for a
connection to the network before being allowed to hook up. It is therefore
recommended that I3 be used in place of IMC2 unless you have some pressing
reason to be on the IMC2 network as well. The need for having both networks
has also been lessened greatly by the activation of the IMC2-I3 intermud
bridge which passes most of the common channel traffic on both networks.

General channel guidelines
--------------------------

This code comes prepackaged with 3 I3 channels. These 3 channels are
the existing set of publicly accessible channels as of now that are
intended for Diku based I3 muds.

The chat channel, dchat, can be made available to your players if you
see fit, but should not be available to newbies. The default level for
this has been set for 10. This channel is currently bridged and can
also be seen by the IMC2 network.

The dimm channel should only be made available to your immortals.
It is intended for the use of immortals only. Suggested level for
it has been set to 101, a first level immortal on our mud.
Adjust as needed. This channel is currently bridged and can also
be seen by the IMC2 network.

The dcode channel is mainly used for asking code related questions
and should probably be limited to the use of your immortals.
Suggested level has been set to 101, a first level immortal on our mud.
Adjust as needed. This channel is currently bridged and can also be
seen by the IMC2 network.
 
Socials can also be sent over channels, but please try to keep this
to a minimum. The social messages will be drawn from your mud's internal
social tables.

This code has been tested and works on the following STOCK codebases:

Smaug 1.02a ( see i3Smaug102.txt ) + the following derivatives:
 * Smaug 1.4a
 * Star Wars Reality 1.0 and 2.0 - see i3swr.txt
 * DOTD 2.2.8 - see i3dotd.txt
 * CalareyMud 1.0 - see i3cm1.txt
 * CalareyMud 2.0 and 3.0 - see i3cm23.txt
 * ResortMud 4.0b - see i3rm4b.txt

Rom 2.4b6 + the following derivatives:
 * RoT 1.4
 * Rogue 2.1a
 * Wurm 2.8c
 * Tartarus 1.0
 * QuickMUD
 * Anatolia 2.1b2 - see i3anatolia.txt
 * Oblivion 1.2 Alpha - see i3oblivion.txt
 * Sundermud 1.0 - see i3sunder.txt
 * EmberMUD 0.9.47 - see i3ember.txt
 * Paradox - see i3paradox.txt

UltraEnvy 0.87j + the following derivatives:
 * Greed 0.99.14 - see i3greed.txt

AckMUD! 4.3.1

Merc 2.2 + the following derivatives:
 * Mythran 3.1.6b
 * Envy 2.2 - see i3envy.txt
 * EOS2 - see i3EOS2.txt
 * Nimud 4 - see i3nimud.txt
 * Godwars Dystopia 1.4 - see i3dystopia.txt
 * Godwars Deluxe - see i3godwars.txt
 * Mindcloud 1.1 - see i3dystopia.txt ( changes are the same )

CircleMud 3.x ( See Circle.txt ) [Circle 2.x is not supported]

If your mud is derived from one of the above listed bases, it should
work without much trouble. Hopefully. :)

One small note - if your codebase comes with I3 preinstalled, and several do,
you can usually upgrade with the files contained in here by simply dropping
the source code files into your src directory. Usually i3.c and i3.h will be
all you need - there should rarely be a reason to change the i3cfg.h file.
If i3cfg.h needs updating, a notice will generally accompany the announcement
of an official release on the support forum.

DO NOT APPLY TO AFKMUD SOURCE! STOP NOW IF USING AFKMUD!

DO NOT APPLY TO 1STMUD SOURCE! STOP NOW IF USING 1STMUD!

I put that in bold letters since text files often refuse to allow me to use
flashing red text to get your attention - AFKMud and 1stMUD codebases both
contain customized installations of I3 which are tailored to the specifics
of each. You should obtain updates from the official releases of each codebase.
Attempting to update using the generic packages will result in compile errors.
The AFKMud Team *WILL NOT* assist in correcting this - they will instead advise
you to obtain the AFKMud version. One would assume the 1stMUD Team will insist
on the same. So do yourself a favor and don't cost yourself alot of time.
