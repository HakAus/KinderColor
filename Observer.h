#pragma once

class Observer {//El coordenadas es un observer el strategy es un observable. El painter statico es llamado por el observer cuando el observable hace el notify. Observable tiene el observer dentro. Hace un update del archivo
public:
	virtual void update();
};