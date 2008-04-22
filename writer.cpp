/*
	Skype Call Recorder
	Copyright (C) 2008 jlh (jlh at gmx dot ch)

	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation; either version 2 of the License, version 3 of
	the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program; if not, write to the Free Software Foundation, Inc.,
	51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

	The GNU General Public License version 2 is included with the source of
	this program under the file name COPYING.  You can also get a copy on
	http://www.fsf.org/
*/

#include <QFileInfo>
#include <QDir>

#include "writer.h"
#include "common.h"

bool AudioFileWriter::open(const QString &fn, long sr, bool s) {
	QFileInfo fi(fn);
	bool b = QDir().mkpath(fi.path());
	if (!b)
		return false;

	file.setFileName(fn);
	sampleRate = sr;
	stereo = s;

	debug(QString("Opening '%1'").arg(file.fileName()));

	return file.open(QIODevice::WriteOnly);
}

void AudioFileWriter::close() {
	debug(QString("Closing '%1'").arg(file.fileName()));
	return file.close();
}

bool AudioFileWriter::remove() {
	debug(QString("Removing '%1'").arg(file.fileName()));
	return file.remove();
}
