# UDPcast MSVC Port

Official homepage: https://www.udpcast.linux.lu/

UDPcast is a file transfer tool that can send data simultaneously to many destinations on a LAN. This can for instance be used to install entire classrooms of PC's at once. The advantage of UDPcast over using other methods (nfs, ftp, whatever) is that UDPcast uses UDP's multicast abilities: it won't take longer to install 15 machines than it would to install just 2.

This repository is an MSVC port of UDPcast. It provides Visual Studio/MSBuild
projects for building the Windows command-line tools:

- `udp-sender.exe`
- `udp-receiver.exe`

Download: [x64](https://nightly.link/a1ive/udpcast/workflows/build/master/udpcast-msvc-x64.zip) | [x86](https://nightly.link/a1ive/udpcast/workflows/build/master/udpcast-msvc-x86.zip)
