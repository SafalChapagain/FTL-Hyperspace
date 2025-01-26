# Updating

Simply replace `Hyperspace.1.6.13.amd64.so` (For Steam) or `Hyperspace.1.6.12.amd64.so` (for GoG/Humble) with the new version from the hyperspace zip.
Updating the Hyperspace SO file is **crucial** for Multiverse updates as they always build for the latest hyperspace.

Patch the new `Hyperspace.ftl` with slipstream if you are using a mod that requires it (*do not patch `Hyperspace.ftl` for Multiverse*)

# Installation

<div class="selector-grid">
    <a class="item" href="steamdeck/select-game-copy">
        <img class="sub-item selector-grid-image" src="{{ '/assets/img/Steam_Deck_colored_logo.svg' | relative_url }}" alt="Steam Deck" />
        <div class="sub-item selector-item-text">Steam Deck Instructions</div>
    </a>
    <a class="item" href="genericlinux/select-game-copy">
        <img class="sub-item selector-grid-image" src="{{ '/assets/img/Tux.svg' | relative_url }}" alt="Generic Linux" />
        <div class="sub-item selector-item-text">Linux Desktop Instructions</div>
    </a>
</div>

# Troubleshooting

#### My game hangs on loading the last `E` in multiverse
- [You have a corrupt save file](#resolving-a-corrupt-save-file)

#### My game hangs on loading but doesn't crash and I hear music
- [You have a corrupt save file](#resolving-a-corrupt-save-file)

#### Resolving a corrupt save file
To potentially fix a corrupted save:
1. Go to `~/.local/share/FasterThanLight/`, you should have a `hs_mv_prof.sav` and `hs_mv_version.sav`
2. Delete the `hs_mv_version.sav`
3. Move the `hs_mv_prof.sav` to another folder (**do not delete it**)
4. Run the game and once it loads to the main menu close it again
5. Move your original `hs_mv_prof.sav` back where it was before, replacing the one that was created by the game
6. If this still doesn't work, delete the entire `~/.local/share/FasterThanLight/` folder
7. ALso disable Steam Cloud Sync if you are using a version of FTL from steam, it'll frequently break the save files.

#### Running FTL gives an error along the lines of "Failed to install hook"
Launching FTL may give this error:  
`Fatal Error Failed to install hook for WeaponControl::RenderAiming: Failed to make copy of original code executable:`  
If you get this error, it's likely that SELinux is preventing the Hyperspace library from being linked. SELinux is common on Fedora Linux. To fix SELinux's interference:
1. Verify that SELinux is running:  
```$ sestatus```
2. If it's enabled, verify that it's in Enforcing mode:  
```$ getenforce```
3. If it is in Enforcing mode, we need to add an exception in SELinux. We do that using `ausearch` to find the SELinux error message, `audit2allow` to generate the exception rule, and `semodule` to install the rule. (If your architecture is not `amd64`, change the `amd64` to the FTL executable your architecture runs.) If there are no search results for the error, you need to launch FTL again to generate the error so `ausearch` can grab it.  
```$ sudo ausearch -c "FTL.amd64" --raw | audit2allow -M FTLMultiverse && sudo semodule -i FTLMultiverse.pp```
4. Verify that the rule loaded correctly:  
```$ sudo semanage module -l | grep FTLMultiverse```  
You should see something along the lines of:  
```FTLMultiverse             400       pp```  
Then, try running FTL again. It should load with Hyperspace/Multiverse/whatever you have installed.
