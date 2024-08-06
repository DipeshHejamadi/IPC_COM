#ifndef IPC_H
#define IPC_H

namespace ipc {

void initialize();
void finalize();
bool registerService(const char* name, int id);
int lookupService(const char* name);

}

#endif // IPC_H
