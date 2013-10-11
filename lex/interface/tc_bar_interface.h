#ifndef LEX_INTERFACE_TC_BAR_INTERFACE_H_
#define LEX_INTERFACE_TC_BAR_INTERFACE_H_

#include <string>

/// <summary>   A tc bar interface, lex will call tc by this </summary>
///
/// <remarks>   Chaohui, 10/11/2013. </remarks>
class TCBarInterface
{
public:
    virtual ~TCBarInterface() {}

    /// <summary>   Enters a long position as specified by the parameters. </summary>
    ///
    /// <remarks>
    ///     EntryLabel - assigns a name that will be displayed in the name label below the entry, and
    ///     can be used to identify the particular entry and to tie an exit to it. An exit can only
    ///     be tied to an entry within the same signal; for more information, see Sell.
    /// </remarks>
    ///
    /// <param name="id">           The identifier. </param>

    virtual void Buy(int id) = 0;

    /// <summary>
    ///     Completely or partially exits one or all of the long entries as specified by the
    ///     parameters.
    /// </summary>
    ///
    /// <remarks>
    ///     ExitLabel - assigns a name that will be displayed in the name label above the exit
    ///     
    ///     An exit can only be tied to an entry within the same signal.For more information, see Buy
    ///     If EntryLabel is not specified, all of the open long entries will be closed.
    /// </remarks>
    ///
    /// <param name="id">           The identifier. </param>

    virtual void Sell(int id) = 0;

    virtual void Open(int bar) = 0;
    virtual void Close(int bar) = 0;
    virtual void High(int bar) = 0;
    virtual void Low(int bar) = 0;
};

#endif  // LEX_INTERFACE_TC_BAR_INTERFACE_H_
