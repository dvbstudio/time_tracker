#include "worker.h"

void CWorker::doWork()
{
          QString postfix = QDateTime::currentDateTime().toString("yy.MM.dd hh.mm.ss.zzz");

    const QString format = "png";
    const QString field = "/img";
    const QString prefix = "screen_";
          QString initialPath;

#ifdef USE_DIALOG

    initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);

    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();

    initialPath += field +
            prefix +
            fostfix +
            format;

    // dialog for select path
    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);

    QStringList mimeTypes;

    foreach (const QByteArray &bf, QImageWriter::supportedMimeTypes())
        mimeTypes.append(QLatin1String(bf));

    fileDialog.setMimeTypeFilters(mimeTypes);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);

    if (fileDialog.exec() != QDialog::Accepted)
        return;

    // path to save
    const QString fileName = fileDialog.selectedFiles().first();

    // save
    if (!originalPixmap.save(/*fileName*/ initialPath)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(/*fileName*/ initialPath)));
    }
#else

    //
    initialPath += QDir::currentPath() +
            field +
            prefix +
            postfix +
            format;


    if ( !p.isNull() )
    {
        // save pixmap
        if (!p.save( initialPath))
            emit error(0x01);
    }
    else
        emit error(0x02);
#endif

    emit finished();

}
