#include "Global.h"


LaserBlast::LaserBlast(Pointf _position, int _ownerId, int _targetId, Pointf _target)
{
    this->constructor(_position, _ownerId, _targetId, _target);
    *(void**)(LaserBlast*)this = VTable_LaserBlast;
    *(void**)(Targetable*)this = VTable_Targetable_LaserBlast; // TODO: Maybe this is faulty, we'll have to see
    this->movingTarget = nullptr;
    this->spinAngle = 0;
    this->spinSpeed = 0;
}

HOOK_METHOD(Projectile, ForceRenderLayer, () -> int)
{
    LOG_HOOK("HOOK_METHOD -> Projectile::ForceRenderLayer -> Begin (ProjectileVTable.cpp)\n")
    return damage.crystalShard ? 1 : -1;
}
