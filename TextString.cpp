#if defined (__APPLE__)
#include "Global.h"

std::string TextString::GetText()
{
    if (!this->isLiteral)
    {
        this->data = G_->GetTextLibrary()->GetText(this->data, G_->GetTextLibrary()->currentLanguage);
    }
    return this->data;
}
#endif
